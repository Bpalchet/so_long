/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:52:09 by bpalchet          #+#    #+#             */
/*   Updated: 2024/12/18 17:52:51 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	ft_puthex(unsigned int n, int flag)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, flag);
	if (n % 16 < 10)
		ft_putchar(n % 16 + '0');
	else
	{
		if (flag == 0)
			ft_putchar((n % 16) + ('a' - 10));
		else if (flag == 1)
			ft_putchar((n % 16) + ('A' - 10));
	}
	len++;
	return (len);
}

/* int main(void)
{
	int n = 13;
	int len = ft_puthex(n, 0);
	printf ("\nla lunghezza stampata e' di %i caratteri", len);
	return (0);
} */