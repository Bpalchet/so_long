/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:00:07 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/18 17:00:10 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*int main (int argc, char **argv)
{
  	int n, m;

	if (argc >= 2)
	{
	printf("char is: %c\n", argv[1][0]);
	n = ft_isascii((int)argv[1][0]);
	m = isascii(argv[1][0]);
	printf ("Il carattere di ritorno e': %d\n", n);
	printf ("Il carattere di ritorno con ISASCII e': %d\n", m);
	}
	return (0);
}*/
