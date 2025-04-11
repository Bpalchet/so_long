/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:18:23 by bpalchet          #+#    #+#             */
/*   Updated: 2024/12/01 17:18:26 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static char	*ft_wr_string(int n, int len)
{
	int		i;
	int		buffer;
	char	*str;

	str = (char *)malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = len - 2;
	buffer = n;
	if (n < 0)
		buffer = -n;
	while (i > 0)
	{
		str[i] = buffer % 10 + 48;
		buffer = buffer / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	else if (n > 0)
		str[0] = buffer % 10 + 48;
	str[len - 1] = '\0';
	return (str);
}

static int	ft_len(int n)
{
	int	len;
	int	i;

	len = 0;
	if (n < 0)
	{
		i = -n;
		while (i >= 1)
		{
			len++;
			i = i / 10;
		}
		return (len + 2);
	}
	if (n > 0)
	{
		i = n;
		while (i >= 1)
		{
			len++;
			i = i / 10;
		}
	}
	return (len + 1);
}

static char	*ft_intmin(void)
{
	char	*str;

	str = (char *)malloc(12 * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
	{
		str = ft_intmin();
		return (str);
	}
	if (n == 0)
	{
		str = (char *)malloc(2 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	len = ft_len(n);
	str = ft_wr_string(n, len);
	return (str);
}

/*(int main(void)
{
    int n = -21474838;
    char *str = ft_itoa(n);

    printf("La stringa numerica: %s\n", str);
    free(str);
    return (0);
}*/
