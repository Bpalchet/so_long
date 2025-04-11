/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:20:17 by bpalchet          #+#    #+#             */
/*   Updated: 2024/12/11 17:20:27 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int		ft_putchar(char a);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);
int		ft_putunbr(unsigned int n);
int		ft_puthex(unsigned int n, int flag);

#endif
