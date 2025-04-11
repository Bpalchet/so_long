/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:45:00 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/22 17:45:07 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	conc_len;

	i = 0;
	j = 0;
	conc_len = 0;
	while (dest[i] != '\0')
		i++;
	while (src[conc_len] != '\0')
		conc_len++;
	if (size <= i)
		conc_len += size;
	else
		conc_len += i;
	while (src[j] != '\0' && (i + 1) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (conc_len);
}

/*int	main (void)
{
	char	dest[20] = "42 Prato";
	char	src[] = "Firenze";

	int		size = ft_strlcat (dest, src, 10);
	
	printf ("Frase concatenata: %s\n", dest);
	printf ("Lunghezza della concatenazione: %d\n", size);
	return (0);
}*/
