/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:51:25 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/23 15:51:29 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	c1;
	char			*last_index;
	int				i;

	c1 = (unsigned char) c;
	i = 0;
	last_index = NULL;
	if (c1 == '\0')
	{
		while (*str != '\0')
			str++;
		return ((char *)str);
	}
	while (str[i] != '\0')
	{
		if (str[i] == c1)
			last_index = (char *)(str + i);
		i++;
	}
	return (last_index);
}

/*int main(void)
{
	char str[] = "ciao a tutti!!";
	char *buffer;
	int c = 'b';
	
	buffer = ft_strrchr(str, c);
	printf ("Stringa trovata: %s\n", buffer);
	printf ("Stringa trovata con STRRCHR: %s\n", strrchr(str, c));
	return(0);
}*/
