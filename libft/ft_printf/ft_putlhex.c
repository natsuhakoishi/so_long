/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:57:33 by yyean-wa          #+#    #+#             */
/*   Updated: 2023/12/07 17:35:43 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlhex(unsigned int n)
{
	char	*hexstr;
	int		result;

	hexstr = "0123456789abcdef";
	result = 0;
	if (n > 15)
		result += ft_putlhex(n / 16);
	result += ft_putchar(hexstr[n % 16]);
	return (result);
}
