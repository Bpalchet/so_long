/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:16:45 by bpalchet          #+#    #+#             */
/*   Updated: 2024/12/02 18:16:51 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*void	ft_tolow(unsigned int i, char *c)
{
	i = i + 0;
	if (*c >= 'A' && *c <= 'Z')
        	*c = *c - 'A' + 'a';
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen((char *)s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

/*int	main(void)
{
	char str[] = "HELLO WORLD";
	ft_striteri(str, ft_tolow);
	printf("Stringa trasformata: %s\n", str);	
	return (0);
}*/
