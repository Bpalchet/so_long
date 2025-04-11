/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:38:36 by bpalchet          #+#    #+#             */
/*   Updated: 2024/10/17 18:26:54 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
//#include <stdio.h>

int	ft_putchar(char a)
{
	write(1, &a, 1);
	return (1);
}

/* int main(void)
{
	char a = 'a';
	int len = ft_putchar(a);
	printf ("\nla lunghezza stampata e' di %i carattere", len);
	return (0);
} */