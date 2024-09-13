/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:57:39 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/08/02 15:58:54 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	a;
	int	len;

	a = -1;
	if (str == NULL)
	{
		str = "(null)";
		len = ft_len(str);
		while (str[++a] != '\0')
			ft_putchar(str[a]);
		return (len);
	}
	else
	{
		len = ft_len(str);
		while (str[++a] != '\0')
			ft_putchar(str[a]);
		return (len);
	}
}
