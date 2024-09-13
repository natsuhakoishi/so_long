/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:57:35 by yyean-wa          #+#    #+#             */
/*   Updated: 2023/12/07 17:16:53 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	result;

	result = 0;
	if (n == -2147483648)
	{
		result += ft_putchar('-');
		result += ft_putnbr(214748364);
		result += ft_putchar('8');
	}
	else if (n < 0)
	{
		result += ft_putchar('-');
		result += ft_putnbr(-n);
	}
	else if (n > 9)
	{
		result += ft_putnbr(n / 10);
		result += ft_putnbr(n % 10);
	}
	else if (n < 10)
	{
		result += ft_putchar(n + '0');
	}
	return (result);
}
/*
int	main(void)
{
	long	a;

	a = 817392136;
	ft_putnbr_fd(a);
	return (0);
}
*/
