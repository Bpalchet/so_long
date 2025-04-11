/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:29:02 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/22 19:29:04 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

/*int main(void)
{
    char c = 'b';
    printf("Maiuscolo di %c: %c\n", c, ft_toupper(c));

    c = 'A';
    printf("Maiuscolo di %c: %c\n", c, ft_toupper(c));

    c = '1';
    printf("Maiuscolo di %c: %c\n", c, ft_toupper(c));

    return (0);
}*/
