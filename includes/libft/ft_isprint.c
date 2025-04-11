/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:36:00 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/18 17:36:03 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/*int main (void)
{
  int c = '\n';
  int risultato;
  int b = isprint (c);
  risultato = ft_isprint(c);
	printf ("Il carattere di ritorno e': %d\n", risultato);
	printf ("Il carattere di ritorno con ISPRINT e': %d\n", b);
  return (0);
}*/
