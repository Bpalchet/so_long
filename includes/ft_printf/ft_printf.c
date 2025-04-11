/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:04:41 by bpalchet          #+#    #+#             */
/*   Updated: 2024/12/10 18:07:26 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>

static int	ft_print_ptr(unsigned long args)
{
	int	len;

	len = 0;
	if (args >= 16)
		len += ft_print_ptr(args / 16);
	if (args % 16 < 10)
		ft_putchar(args % 16 + '0');
	else
		ft_putchar((args % 16) + ('a' - 10));
	len++;
	return (len);
}

static int	ft_print_pointer(unsigned long args)
{
	int	len;

	if (args == 0)
	{
		len = write(1, "(nil)", 5);
		return (len);
	}
	len = write(1, "0x", 2);
	len += ft_print_ptr(args);
	return (len);
}

static int	ft_process_format(char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, void *)));
	else if (format == 'p')
	{
		return (len = ft_print_pointer((unsigned long) \
			va_arg(args, unsigned long *)));
	}
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		tot_len;

	tot_len = 0;
	va_start(args, str);
	if (str == NULL)
		return (-1);
	while (*str)
	{
		if (*str == '%' && (*str + 1) != '\0')
		{
			str++;
			tot_len += ft_process_format(*str, args);
		}
		else
			tot_len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (tot_len);
}

/* int main()
{
	char *s = NULL;

	ft_printf("%d\n", ft_printf("NULL %s NULL ", s));
	printf("%d\n", printf("NULL %s NULL ", s));
	
	ft_printf("%d\n", ft_printf("%d\n", INT_MIN));
    printf("%d\n", printf("%d\n", INT_MIN));

    ft_printf("%d\n", ft_printf("%X\n", INT_MIN));
    printf("%d\n", printf("%X\n", INT_MIN));

    ft_printf("%d\n", ft_printf("%x\n", INT_MIN));
    printf("%d\n", printf("%x\n", INT_MIN));

    char    *p = "";
    ft_printf("%d\n", ft_printf("%p\n", p));
    printf("%d\n", printf("%p\n", p));

    char    *st = "gegeg";
    ft_printf("%d\n", ft_printf("Ciao, %s\n", st));
    printf("%d\n", printf("Ciao, %s\n", st));

    unsigned int    u = INT_MAX;
    ft_printf("%d\n", ft_printf("%u\n", u));
    printf("%d\n", printf("%u\n", u));

    unsigned int    x = INT_MAX;
    ft_printf("%d\n", ft_printf("%x\n", x));
    printf("%d\n", printf("%x\n", x));
    ft_printf("%d\n", ft_printf("%X\n", x));
    printf("%d\n", printf("%X\n", x));
}    */