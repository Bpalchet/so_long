/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:04:58 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/23 16:05:00 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	unsigned char		c1;
	unsigned char		c2;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 == '\0' || c2 == '\0')
		{
			return (c1 - c2);
		}
		if (c1 != c2)
		{
			return (c1 - c2);
		}
		i++;
	}
	return (0);
}

/*int	main (void)
{
	int diff;
	int n = 0;
	char s1[] = "cacioppo";
	char s2[] = "strappo";
	diff = ft_strncmp (s1, s2, n);
	printf ("%d\n", diff);
	printf ("Comparazione trovata con STRNCMP: %d\n", strncmp(s1, s2, n));
	return (0);
}*/
