/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:12:57 by bpalchet          #+#    #+#             */
/*   Updated: 2024/10/23 16:53:44 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
//#include <stdio.h>

static int	ft_putnbr_rec(int nb, int i)
{
	char	c;

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		i++;
	}
	if (nb >= 10)
		i = ft_putnbr_rec((nb / 10), i);
	c = (nb % 10) + 48;
	write(1, &c, 1);
	i++;
	return (i);
}

int	ft_putnbr(int nb)
{
	return (ft_putnbr_rec(nb, 0));
}

/* int main(void)
{
	int n = 2147483647;
	int len = ft_putnbr(n);
	printf ("\nla lunghezza stampata e' di %i caratteri", len);
	return (0);
} */