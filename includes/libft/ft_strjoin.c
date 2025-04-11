/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:05:50 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/26 17:05:59 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_conca(char *concat, char const *s2, int i)
{
	int	j;

	j = 0;
	while (s2[j])
	{
		concat[i] = s2[j];
		i++;
		j++;
	}
	concat[i] = '\0';
	return (concat);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		slen1;
	int		slen2;
	int		i;
	char	*concat;

	slen1 = ft_strlen((char *) s1);
	slen2 = ft_strlen((char *) s2) + 1;
	concat = malloc((slen1 + slen2) * sizeof(char));
	if (concat == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	concat = ft_conca(concat, s2, i);
	return (concat);
}

/*int main(void)
{
	const char *s1 = "Ciao ";
	const char *s2 = "a tutti";
	char *conc;

	conc = ft_strjoin(s1, s2);
	

    	if (conc != NULL)
    	{
        printf("Stringa originale 1: %s\n", s1);
        printf("Stringa originale 2: %s\n", s2);
        printf("Stringa concatenata: %s\n", conc);

        // Ricordati di liberare la memoria quando non serve più
        free(conc);
	}
	else
        	printf("Errore nell'allocazione della memoria.\n");
    	return (0);
}*/
