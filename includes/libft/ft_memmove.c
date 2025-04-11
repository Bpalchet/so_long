/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:49:55 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/21 18:49:57 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (d < s)
	{
		while (n > 0)
		{
			*d++ = *s++;
			n--;
		}
	}
	else if (d > s)
	{
		d += n;
		s += n;
		while (n > 0)
		{
			*(--d) = *(--s);
			n--;
		}
	}
	return (dest);
}
/*int main(void) // prova con numeri
{
    int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *dest = malloc(5 * sizeof(int));
    int *buffer = malloc(5 * sizeof(int));
    size_t n = 5 * sizeof(int);

    // Sposta usando ft_memcpy
    ft_memmove(dest, src + 3, n);
    printf("Dest after ft_memmove: ");
    size_t i = 0;
    while (i < 5) {
        printf("%d ", dest[i]);
        i++;
    }
    printf("\n");

    // Copia usando memcpy
    memmove(buffer, src + 3, n);
    printf("Buffer after memmove: ");
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

/*int main(void)  //prova con lettere
{
    char src[] = "Ciao a tutti!!!";
    char dest[20];
    char buffer[20];
    size_t n = 5;

    // Sposta usando ft_memcpy
    ft_memmove(dest, src, n);
    dest[n] = '\0';
    printf("Dest after ft_memmove: %s\n", dest);
    printf("\n");

    // Sposta usando memcpy
    memmove(buffer, src, n);
    buffer[n] = '\0';   
    printf("Buffer after memmove: %s\n", buffer);
    return 0;
}*/
