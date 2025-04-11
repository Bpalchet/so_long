/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:47:34 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/22 19:47:36 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - ('A' - 'a'));
	return (c);
}

/*int main(void)
{
    char c = 'B';
    printf("Minuscolo di %c: %c\n", c, ft_tolower(c));

    c = 'e';
    printf("Minuscolo di %c: %c\n", c, ft_tolower(c));

    c = '1';
    printf("Minuscolo di %c: %c\n", c, ft_tolower(c));

    return (0);
}*/
