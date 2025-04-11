/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:06:26 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/23 18:06:33 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static char	*find_match(const char *p1, const char *p2, size_t i)
{
	const char	*start;

	start = p1;
	while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2 && i > 0)
	{
		p1++;
		p2++;
		i--;
	}
	if (*p2 == '\0')
		return ((char *)start);
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*p1;
	char		*match;
	size_t		i;

	match = NULL;
	p1 = big;
	if (*little == '\0')
		return ((char *) big);
	if (*big == '\0' || len == 0)
		return (NULL);
	while (*p1 != '\0' && len > 0)
	{
		i = len;
		match = find_match(p1, little, i);
		if (match)
			return (match);
		p1++;
		len--;
	}
	return (NULL);
}

/*#include <bsd/string.h> // aggiunta la libreria bsd.
				Ricordare il flag -lbsd in gcc

int	main(void)
{
	const char big[] = "123 stella!!";
	const char little[] = "3";
	char *risultato;
	size_t len = 5;
	
	risultato = ft_strnstr(big, little, len);
	printf("Il buffer rilevato con FT: %s\n", risultato);
	printf("stringa trovata con STRNSTR: %s\n", strnstr(big, little, len));
	return (0);
}*/
