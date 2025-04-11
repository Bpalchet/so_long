/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:43:27 by bpalchet          #+#    #+#             */
/*   Updated: 2024/10/24 16:45:48 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
//#include <stdio.h>

int	ft_putstr(char *str)
{
	int	len;

	if (str == NULL)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	write (1, str, len);
	return (len);
}

/* int main(void)
{
	char *str = "Ciao mamma guarda come mi diverto";
	int len = ft_putstr(str);
	printf ("\nla lunghezza stampata e' di %i caratteri", len);
	return (0);
} */