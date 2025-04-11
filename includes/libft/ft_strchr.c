/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:03:28 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/23 15:03:31 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	unsigned char	c1;

	c1 = (unsigned char) c;
	if (c1 == '\0')
	{
		while (*str != '\0')
			str++;
		return ((char *)str);
	}
	while (*str != '\0')
	{
		if (*str == c1)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

/*int main(void)
{
	char str[] = "ciao a tutti!!";
	char *buffer;
	int c = 't';
	
	buffer = ft_strchr(str, c);
	printf ("Stringa trovata: %s\n", buffer);
	printf ("Stringa trovata con STRCHR: %s\n", strchr(str, c));
	return(0);
}*/
