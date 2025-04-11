/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:04:31 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/26 18:04:38 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static char	*ft_trim(char const *s1, unsigned int new_len, unsigned int start)
{
	char			*trimmed;
	unsigned int	i;

	if (new_len == 0)
	{
		trimmed = malloc(1);
		if (trimmed == NULL)
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	trimmed = malloc((new_len + 1) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	i = 0;
	while (i < new_len)
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	slen1;
	unsigned int	start;
	unsigned int	end;
	unsigned int	new_len;
	char			*trimmed;

	if (!s1)
		return (NULL);
	if (!set || *s1 == '\0')
		return (ft_strdup(""));
	slen1 = ft_strlen((char *)s1);
	start = 0;
	end = slen1 - 1;
	while (start <= end && ft_strchr(set, s1[start]))
		start++;
	while (end >= start && ft_strchr(set, s1[end]))
		end--;
	new_len = slen1 - start - (slen1 - 1 - end);
	trimmed = ft_trim(s1, new_len, start);
	return (trimmed);
}

/*int main(void)
{
	const char *s1 = "a*spazzacamino**e";
	const char *set = "a*e";
	char *trimmed;

	trimmed = ft_strtrim(s1, set);
	if (trimmed != NULL)
    	{
        printf("Stringa da trimmare: %s\n", s1);
        printf("Trim da eseguire: %s\n", set);
        printf("Stringa trimmata: %s\n", trimmed);
        // Ricordati di liberare la memoria quando non serve più
        free(trimmed);
	}
	else
        	printf("Errore nell'allocazione della memoria.\n");
    	return (0);
}*/
