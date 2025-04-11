/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:54:17 by bpalchet          #+#    #+#             */
/*   Updated: 2024/12/02 19:54:24 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
	write (fd, "\n", 1);
}

/*int	main(void)
{
	char	s[] = "bella ciao";
	int	fd = 1;
//	int	fd = open("text.txt", O_RDWR);
	ft_putendl_fd(s, fd);
	return (0);
}*/
