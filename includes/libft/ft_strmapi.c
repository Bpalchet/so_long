/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:52:18 by bpalchet          #+#    #+#             */
/*   Updated: 2024/12/01 18:52:22 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*char	ft_toup(unsigned int i, char c)
{
	i = i + 0;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*result;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*int main(void)
{
    char *s = "hello";
    char *result = ft_strmapi(s, ft_toup);

    if (result)
    {
        printf("%s\n", result);  // Stampa "HELLO"
        free(result);  // Ricorda di liberare la memoria
    }
    else
    {
        printf("Errore nell'allocazione della memoria\n");
    }
    return(0);
}*/
