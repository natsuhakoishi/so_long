/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:57:44 by yyean-wa          #+#    #+#             */
/*   Updated: 2023/12/07 18:11:25 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putusnbr(unsigned int n)
{
	int	result;

	result = 0;
	if (n > 9)
		result += ft_putnbr(n / 10);
	result += ft_putchar(n % 10 + '0');
	return (result);
}
