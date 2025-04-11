/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:13:57 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/20 18:14:01 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_bzero(void *str, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = str;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/*int main (void)
{
  	char buffer[] = "ciao a tutti";
  	char *buffer1;
  	char buffer2[50];
  	int n = 5;
	printf ("String iniziale: %s\n", buffer);
	buffer1 = ft_bzero(buffer, n);
	printf ("String modificata: %s\n", buffer1);
	*buffer2 = *buffer1;
	bzero(buffer, 5);
	printf ("String con BZERO: %s\n", buffer);
	return (0);
}*/
