/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:46:19 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/18 15:46:31 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/*int main (void)
{
  int c = 'P';
  int risultato;
  int b = isalpha (c);
  risultato = ft_isalpha(c);
	printf ("Il carattere di ritorno e': %d\n", risultato);
	printf ("Il carattere di ritorno con ISALPHA e': %d\n", b);
  return (0);
}*/
