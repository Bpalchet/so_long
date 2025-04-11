/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:21:22 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/18 18:21:26 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memset(void *str, int value, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = str;
	i = 0;
	while (i < n)
	{
		ptr[i] = value;
		i++;
	}
	return (ptr);
}

/*int main (void)
{
  	char buffer[10];
  	char *buffer1;
  	char *buffer2;
  	int value = 48;
  	size_t n = 10;
	buffer1 = ft_memset(buffer, value, n);
	printf ("%s\n", buffer1);
	buffer2 = memset(buffer, value, n);
	printf ("%s\n", buffer2);
	return (0);
}*/
