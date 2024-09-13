/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:53:43 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/09/09 18:38:19 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floodfill(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
	{
		game->map_valid = 1;
		return ;
	}
	if (game->tmp_map[y][x] == 'E' || game->tmp_map[y][x] == 'C' || \
		game->tmp_map[y][x] == '0' || game->tmp_map[y][x] == 'P' || \
		game->tmp_map[y][x] == 'A')
	{
		game->tmp_map[y][x] = 'F';
		floodfill(game, x + 1, y);
		floodfill(game, x - 1, y);
		floodfill(game, x, y + 1);
		floodfill(game, x, y - 1);
	}
	return ;
}

void	ft_mapcpy(t_game *game)
{
	int	y;
	int	x;

	game->tmp_map = ft_calloc(game->height, sizeof(char *));
	if (!game->tmp_map)
	{
		game->map_valid = 1;
		return ;
	}
	ft_mapmake(game);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			game->tmp_map[y][x] = game->map[y][x];
			x++;
		}
		y++;
	}
	floodfill(game, game->ffx, game->ffy);
	ft_scanmap(game);
}

int	ft_mapmake(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->height)
	{
		game->tmp_map[y] = ft_calloc(game->width + 1, sizeof(char));
		if (!game->tmp_map[y])
		{
			game->map_valid = 1;
			while (y > 0)
				free(game->tmp_map[--y]);
			free(game->tmp_map);
			return (0);
		}
		y++;
	}
	return (1);
}

void	ft_scanmap(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->tmp_map[y][x] == 'E' || \
				game->tmp_map[y][x] == 'C')
			{
				game->map_valid = 1;
				return ;
			}
			x++;
		}
		y++;
	}
}
