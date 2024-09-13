/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:57:27 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/08/02 15:58:40 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putlhex(unsigned int n);
int	ft_putnbr(int n);
int	ft_putpter(unsigned long long ptr);
int	ft_putstr(char *str);
int	ft_putuhex(unsigned int n);
int	ft_putusnbr(unsigned int n);
int	ft_len(char *str);

#endif
