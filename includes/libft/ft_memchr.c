/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:25:01 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/23 16:25:09 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;
	unsigned char		j;

	ptr = s;
	j = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == j)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	char s[] = "attenzione";
	int c = 'n';
	size_t n = 5;
	
	printf ("%p\n", ft_memchr(s, c, n));
	printf ("risultato ottenuto con MEMCHR: %p\n", memchr(s, c, n));
	return (0);
}*/
