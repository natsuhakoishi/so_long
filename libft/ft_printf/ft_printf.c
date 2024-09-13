/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:57:30 by yyean-wa          #+#    #+#             */
/*   Updated: 2023/12/07 18:57:26 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(const char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		len += ft_putpter(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_putusnbr(va_arg(args, unsigned int));
	else if (format == 'x')
		len += ft_putlhex(va_arg(args, unsigned int));
	else if (format == 'X')
		len += ft_putuhex(va_arg(args, unsigned int));
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		a;
	va_list	args;
	int		len;

	a = 0;
	len = 0;
	va_start(args, str);
	while (str[a])
	{
		if (str[a] == '%')
		{
			len += ft_formats(str[a + 1], args);
			a++;
		}
		else
			len += ft_putchar(str[a]);
		a++;
	}
	va_end(args);
	return (len);
}
/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char	test1 = 'c';
	char	*test2 = "Chara";
	char	test3 = 0;
	int		test4 = 49;
	int		test5 = -94;
	char	test6 = '~';
	char	test7 = 0;

	ft_printf("TEST : %c\n", test1);
	printf("STDIO: %c\n\n", test1);
	ft_printf("TEST : %s\n", test2);
	printf("STDIO: %s\n\n", test2);
	ft_printf("TEST : %p %p\n", &test3, &test7);
	printf("STDIO: %p %p\n\n", &test3, &test7);
	ft_printf("TEST : %d\n", test4);
	printf("STDIO: %d\n\n", test4);
	ft_printf("TEST : %i\n", test4);
	printf("STDIO: %i\n\n", test4);
	ft_printf("TEST : %d\n", test5);
	printf("STDIO: %d\n\n", test5);
	ft_printf("TEST : %i\n", test5);
	printf("STDIO: %i\n\n", test5);
	ft_printf("TEST : %u\n", test4);
	printf("STDIO: %u\n\n", test4);
	ft_printf("TEST : %u\n", test5);
	printf("STDIO: %u\n\n", test5);
	ft_printf("TEST : %x\n", test6);
	printf("STDIO: %x\n\n", test6);
	ft_printf("TEST : %X\n", test6);
	printf("STDIO: %X\n\n", test6);
	ft_printf("TEST : %%\n");
	printf("STDIO: %%\n\n");
	return (0);
}
*/
