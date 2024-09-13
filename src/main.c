/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:02:27 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/09/12 16:12:22 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_input(int key, t_game *game)
{
	if (key == 53)
		exit_game(game);
	else if ((key == 13 || key == 126) && \
		game->map[game->player_y / 64 - 1][game->player_x / 64] != '1')
		go_up(game);
	else if ((key == 1 || key == 125) && \
		game->map[game->player_y / 64 + 1][game->player_x / 64] != '1')
		go_down(game);
	else if ((key == 0 || key == 123) && \
		game->map[game->player_y / 64][game->player_x / 64 - 1] != '1')
		go_left(game);
	else if ((key == 2 || key == 124) && \
		game->map[game->player_y / 64][game->player_x / 64 + 1] != '1')
		go_right(game);
	if (game->enemy_x == game->player_x && game->enemy_y == game->player_y)
		exit_killed(game);
	return (0);
}

void	ft_sprites(t_game *game)
{
	game->bg_path = "./sprites/bg.xpm";
	game->bg_image = mlx_xpm_file_to_image(game->mlx, game->bg_path, \
			&game->image_size, &game->image_size);
	game->col_path = "./sprites/col.xpm";
	game->col_image = mlx_xpm_file_to_image(game->mlx, game->col_path, \
			&game->image_size, &game->image_size);
	game->wall_path = "./sprites/wall.xpm";
	game->wall_image = mlx_xpm_file_to_image(game->mlx, game->wall_path, \
			&game->image_size, &game->image_size);
	game->exit_path = "./sprites/exit.xpm";
	game->exit_image = mlx_xpm_file_to_image(game->mlx, game->exit_path, \
			&game->image_size, &game->image_size);
}

int	game_init(char	*map, t_game *game)
{
	game->player_x = 0;
	game->player_y = 0;
	game->ffx = 0;
	game->ffy = 0;
	game->map_valid = 0;
	game->col_done = 0;
	game->col_count = 0;
	game->move_count = 0;
	game->height = 0;
	game->width = 0;
	game->animation_count = 0;
	game->enemy_count = 0;
	ft_sprites(game);
	init_map(map, game);
	game->randomizer = game->col_count + game->height + game->width;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(1, "\nError\nMap Error.\n\n", 19);
		return (0);
	}
	game.mlx = mlx_init();
	game_init(argv[1], &game);
	game.window = mlx_new_window(game.mlx, game.width * 64, \
		game.height * 64, "so_long");
	mlx_hook(game.window, 17, (1L << 0), exit_game, &game);
	mlx_key_hook(game.window, ft_input, &game);
	mlx_loop_hook(game.mlx, image_loop, &game);
	mlx_loop(game.mlx);
}
