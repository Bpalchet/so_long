/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:32:41 by bpalchet          #+#    #+#             */
/*   Updated: 2024/11/25 18:32:52 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (ptr);
	ptr = ft_memset(ptr, 0, total_size);
	return (ptr);
}

/*int	main(void)
{
	const char *array;
	int i = 0;
	
	array = ft_calloc(10, sizeof(char));
	while (i <= 10)
	{
		printf ("Pos. %d, %d\n", i, (int) array[i]);
		i++;
	}
	return (0);
}*/
