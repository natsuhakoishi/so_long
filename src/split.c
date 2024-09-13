/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:27:04 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/09/04 18:17:20 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_substr1(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	a = malloc(sizeof(char) * len + 1);
	if (!a)
		return (NULL);
	a[0] = '\0';
	if (start <= len)
	{
		while (i < len)
		{
			a[i] = s[start + i];
			++i;
		}
	}
	a[i] = '\0';
	return (a);
}

static int	countlen(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != c && *s)
	{
		++count;
		++s;
	}
	return (count);
}

static int	getwords(char const *s, char c, t_game *game)
{
	while (*s)
	{
		if (*s != c)
		{
			++game->height;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (game->height);
}

char	**split(char const *s, char c, t_game *game)
{
	char	**a;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	a = malloc(sizeof(char *) * (getwords(s, c, game) + 1));
	if (!a)
		return (NULL);
	game->width = countlen(s, c);
	while (*s)
	{
		if (countlen(s, c) != 0)
		{
			if (game->width != countlen(s, c))
				game->map_valid = 1;
			a[i] = ft_substr1(s, 0, countlen(s, c));
			s += countlen(s, c);
			++i;
		}
		else
			++s;
	}
	a[i] = NULL;
	return (a);
}
