/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:46:39 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/18 17:46:42 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/*int main (int argc, char **argv)
{
  	int n, m;

	if (argc >= 2)
	{
	printf("String is: %s\n", argv[1]);
	n = ft_strlen(argv[1]);
	m = strlen(argv[1]);
	printf ("La lunghezza della stringa e': %d\n", n);
	printf ("La lunghezza della stringa con STRLEN e': %d\n", m);
	}
	return (0);
}*/
