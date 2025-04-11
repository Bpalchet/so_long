/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:56:36 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/26 15:56:44 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		slen;
	char		*copia;

	slen = ft_strlen((char *) s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	copia = malloc((len + 1) * sizeof(char));
	if (copia == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copia[i] = s[start + i];
		i++;
	}
	copia[i] = '\0';
	return (copia);
}

/*int main(void)
{
	const char *s = "Ciao, mondo!";
	char *sub;

	sub = ft_substr(s, 16, 999999);
	

    	if (sub != NULL)
    	{
        printf("Stringa originale: %s\n", s);
        printf("Sottostringa: %s\n", sub);

        // Ricordati di liberare la memoria quando non serve più
        free(sub);
	}
	else
        	printf("Errore nell'allocazione della memoria.\n");
    	return (0);
}*/
