/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:57:46 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/08/02 15:58:26 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(char *str)
{
	int	a;

	a = 0;
	while (*str++ != '\0')
		a++;
	return (a);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%ld\n", ft_strlen("haha"));
	return (0);
}
*/
