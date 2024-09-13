/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:57:41 by yyean-wa          #+#    #+#             */
/*   Updated: 2023/12/07 17:36:19 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuhex(unsigned int n)
{
	char	*hexstr;
	int		result;

	hexstr = "0123456789ABCDEF";
	result = 0;
	if (n > 15)
		result += ft_putuhex(n / 16);
	result += ft_putchar(hexstr[n % 16]);
	return (result);
}
