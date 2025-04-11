/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:10:41 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/24 18:10:56 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	ft_number(const char *nptr)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while ((*nptr == ' ') || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if ((*nptr == '+') || (*nptr == '-'))
	{
		if (*nptr == '-')
		{
			sign = sign * -1;
			nptr++;
		}
		else
			nptr++;
	}
	if (!(*nptr >= '0' && *nptr <= '9'))
		return (0);
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	return (num * sign);
}

int	ft_atoi(const char *nptr)
{
	int	num;

	if (!(*nptr >= '0' && *nptr <= '9') && (*nptr != '+') && (*nptr != '-')
		&& (*nptr != ' ') && (!(*nptr >= 9 && *nptr <= 13)))
		return (0);
	num = ft_number (nptr);
	return (num);
}

/*int	main(void)
{
	char nptr[] = "\f    +-1234rhk56";
	
	printf("Il numero trovato con FT_ATOI: %d\n", ft_atoi(nptr));
	printf("il numero trovato con ATOI: %d\n", atoi(nptr));
	return (0);
}*/
