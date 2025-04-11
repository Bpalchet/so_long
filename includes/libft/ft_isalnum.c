/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:51:23 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/18 16:51:26 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*int main (void)
{
  int c = '8';
  int risultato;
  int b = isalnum (c);
  risultato = ft_isalnum(c);
	printf ("Il carattere di ritorno e': %d\n", risultato);
	printf ("Il carattere di ritorno con ISALNUM e': %d\n", b);
  return (0);
}*/
