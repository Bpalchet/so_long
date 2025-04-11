/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:15:56 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/20 19:15:59 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char		*s;
	unsigned char			*d;
	size_t					i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (!d && !s)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*int main(void)
{
    int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *dest = malloc(5 * sizeof(int));
    int *buffer = malloc(5 * sizeof(int));
    size_t n = 5 * sizeof(int);

    // Copia usando ft_memcpy
    ft_memcpy(dest, src, n);
    printf("Dest after ft_memcpy: ");
    size_t i = 0;
    while (i < 5) {
        printf("%d ", dest[i]);
        i++;
    }
    printf("\n");

    // Copia usando memcpy
    memcpy(buffer, src, n);
    printf("Buffer after memcpy: ");
    i = 0;
    while (i < 5) {
        printf("%d ", buffer[i]);
        i++;
    }
    printf("\n");

    // Liberazione della memoria
    free(dest);
    free(buffer);

    return 0;
}*/
