/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:06:05 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/26 15:06:07 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *str)
{
	char	*copia;
	int		i;
	int		len;

	len = ft_strlen((char *) str) + 1;
	copia = malloc(len * sizeof(char));
	if (copia == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copia[i] = str[i];
		i++;
	}
	copia[i] = '\0';
	return (copia);
}

/*int main(void)
{
	const char *str = NULL;
	char *copia = ft_strdup(str);

    if (copia != NULL)
    {
        printf("Stringa originale: %s\n", str);
        printf("Stringa copiata: %s\n", copia);

        // Ricordati di liberare la memoria quando non serve più
        free(copia);
    } else
        printf("Errore nell'allocazione della memoria.\n");
    return (0);
}*/
