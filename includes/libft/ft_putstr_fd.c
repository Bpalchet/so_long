/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:34:49 by bpalchet          #+#    #+#             */
/*   Updated: 2024/12/02 19:34:52 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

/*int	main(void)
{
	char	s[] = "bella ciao";
	int	fd = 1;
//	int	fd = open("text.txt", O_RDWR);
	ft_putstr_fd(s, fd);
	return (0);
}*/
