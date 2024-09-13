/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:57:37 by yyean-wa          #+#    #+#             */
/*   Updated: 2023/12/07 19:13:07 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned long long n)
{
	char	*hexstr;
	int		res;

	hexstr = "0123456789abcdef";
	res = 0;
	if (n > 15)
		res += ft_puthex(n / 16);
	res += ft_putchar(hexstr[n % 16]);
	return (res);
}

int	ft_putpter(unsigned long long ptr)
{
	int	result;

	result = 0;
	result += ft_putstr("0x");
	result += ft_puthex(ptr);
	return (result);
}
