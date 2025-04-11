/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:30:55 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/18 16:31:13 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*int main (void)
{
  int c = '3';
  int risultato;
  int b = isdigit (c);
  risultato = ft_isdigit(c);
	printf ("Il carattere di ritorno e': %d\n", risultato);
	printf ("Il carattere di ritorno con ISDIGIT e': %d\n", b);
  return (0);
}*/
