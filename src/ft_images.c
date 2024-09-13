/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:10:38 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/09/12 18:07:37 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_loop(t_game *game)
{
	if (game->map[game->enemy_y / 64 - 1][game->enemy_x / 64] != '1' \
	&& game->randomizer % 4 == 0)
		game->enemy_y -= 64;
	else if (game->map[game->enemy_y / 64 + 1][game->enemy_x / 64] != '1' \
	&& game->randomizer % 4 == 1)
		game->enemy_y += 64;
	else if (game->map[game->enemy_y / 64][game->enemy_x / 64 - 1] != '1' \
	&& game->randomizer % 4 == 2)
		game->enemy_x -= 64;
	else if (game->map[game->enemy_y / 64][game->enemy_x / 64 + 1] != '1' \
	&& game->randomizer % 4 == 3)
		game->enemy_x += 64;
	if (game->enemy_x == game->player_x && game->enemy_y == game->player_y)
		exit_killed(game);
}

void	player_loop(t_game *game)
{
	if (game->animation_count % 32 < 16)
	{
		game->player_path = "./sprites/ryo.xpm";
		game->enemy_path = "./sprites/nijika.xpm";
	}
	if (game->animation_count % 32 >= 16)
	{
		game->player_path = "./sprites/ryo2.xpm";
		game->enemy_path = "./sprites/nijika2.xpm";
	}
	game->player_image = mlx_xpm_file_to_image(game->mlx, game->player_path, \
			&game->image_size, &game->image_size);
	if (game->enemy_count == 1)
		game->enemy_image = mlx_xpm_file_to_image(game->mlx, game->enemy_path, \
			&game->image_size, &game->image_size);
}

void	asset_loop(t_game *game)
{
	game->tmpx = 0;
	game->tmpy = 0;
	while (game->tmpy < game->height)
	{
		game->tmpx = 0;
		while (game->tmpx < game->width)
		{
			if (game->map[game->tmpy][game->tmpx] == '1')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->wall_image, game->tmpx * 64, game->tmpy * 64);
			if (game->map[game->tmpy][game->tmpx] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->col_image, game->tmpx * 64, game->tmpy * 64);
			if (game->map[game->tmpy][game->tmpx] == 'E' && \
				game->col_count == game->col_done)
				mlx_put_image_to_window(game->mlx, game->window, \
				game->exit_image, game->tmpx * 64, game->tmpy * 64);
			++game->tmpx;
		}
		++game->tmpy;
	}
}

int	bg_loop(t_game *game)
{
	game->tmpx = 0;
	game->tmpy = 0;
	while (game->tmpy < game->height)
	{
		game->tmpx = 0;
		while (game->tmpx < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->window, game->bg_image, \
				game->tmpx * 64, game->tmpy * 64);
			++game->tmpx;
		}
		++game->tmpy;
	}
	return (0);
}

int	image_loop(t_game *game)
{
	char	*count;

	player_loop(game);
	bg_loop(game);
	asset_loop(game);
	game->randomizer = (game->randomizer + game->randomizer * 1738) % 727;
	if (game->enemy_count == 1 && game->animation_count % 4 == 0)
		enemy_loop(game);
	mlx_string_put(game->mlx, game->window, 5, 0, 16777215, \
					"Movement Counter: ");
	count = ft_itoa(game->move_count);
	mlx_string_put(game->mlx, game->window, 175, 0, 16777215, count);
	free (count);
	mlx_put_image_to_window(game->mlx, game->window, game->player_image, \
		game->player_x, game->player_y);
	mlx_put_image_to_window(game->mlx, game->window, game->enemy_image, \
		game->enemy_x, game->enemy_y);
	++game->animation_count;
	return (0);
}
