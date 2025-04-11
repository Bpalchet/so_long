/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:27:25 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/22 17:27:28 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static unsigned int	ft_length(const char *src)
{
	unsigned int	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	return (src_len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	src_len;
	unsigned int	copy_len;
	unsigned int	i;

	src_len = ft_length(src);
	i = 0;
	if (size == 0)
	{
		return (src_len);
	}
	if (src_len >= size)
	{
		copy_len = size - 1;
	}
	else
	{
		copy_len = src_len;
	}
	while (i < copy_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[copy_len] = '\0';
	return (src_len);
}

/*int main(void)
{
    char dest[12];
    const char *src = "Hello!!!";
    
    unsigned int copied_length = ft_strlcpy(dest, src, 3);
    
    
    printf("Dest: %s\n", dest);
    printf("Length of src: %u\n", copied_length);
    
    return 0;
}*/
