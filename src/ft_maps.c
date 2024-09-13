/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:04:09 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/09/12 16:12:07 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_all(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] != 'P' && game->map[y][x] != '1' && \
			game->map[y][x] != 'C' && game->map[y][x] != '0' && \
			game->map[y][x] != 'E' && game->map[y][x] != 'A')
				game->map_valid = 1;
		}
	}
}

void	check_wall(t_game *game)
{
	int	y;
	int	x;

	y = 1;
	x = 0;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1')
			game->map_valid = 1;
		++x;
	}
	while (y < game->height - 1)
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
			game->map_valid = 1;
		++y;
	}
	x = 0;
	while (game->map[game->height - 1][x])
	{
		if (game->map[game->height - 1][x] != '1')
			game->map_valid = 1;
		++x;
	}
}

void	pp_utils(int *check_p, int *check_a, int *check_e, t_game *game)
{
	if (game->map[game->tmpy][game->tmpx] == 'P')
	{
		game->ffx = game->tmpx;
		game->ffy = game->tmpy;
		game->player_x = game->tmpx * 64;
		game->player_y = game->tmpy * 64;
		++*check_p;
	}
	if (game->map[game->tmpy][game->tmpx] == 'A')
	{
		game->enemy_x = game->tmpx * 64;
		game->enemy_y = game->tmpy * 64;
		++*check_a;
	}
	if (game->map[game->tmpy][game->tmpx] == 'E')
	{
		game->exit_x = game->tmpx * 64;
		game->exit_y = game->tmpy * 64;
		++*check_e;
	}
	if (game->map[game->tmpy][game->tmpx] == 'C')
		++game->col_count;
}

void	player_position(t_game *game)
{
	int	check_p;
	int	check_a;
	int	check_e;

	game->tmpy = -1;
	check_p = 0;
	check_a = 0;
	check_e = 0;
	while (++game->tmpy < game->height)
	{
		game->tmpx = -1;
		while (++game->tmpx < game->width)
		{
			pp_utils(&check_p, &check_a, &check_e, game);
		}
	}
	if (check_p != 1 || check_a > 1 || check_e != 1 || game->col_count < 1)
		game->map_valid = 1;
	game->enemy_count = check_a;
}

int	init_map(char *map, t_game *game)
{
	int		fd;
	char	*temp;
	int		a;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		write(1, "\nError\nMap fd Error.\n\n", 22);
		exit(0);
	}
	temp = malloc(sizeof(char) * (10000 + 1));
	a = read(fd, temp, 10000);
	temp[a] = 0;
	game->map = split(temp, '\n', game);
	free (temp);
	if (game->map_valid == 1)
		exit_error(game);
	check_all(game);
	check_wall(game);
	player_position(game);
	ft_mapcpy(game);
	if (game->map_valid == 1)
		exit_error(game);
	return (0);
}
