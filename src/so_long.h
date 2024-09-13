/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:45:12 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/09/05 19:21:05 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"

typedef struct s_game
{
	void	*mlx;

	void	*window;
	int		image_size;

	int		player_x;
	int		player_y;
	char	*player_path;
	void	*player_image;
	int		ffx;
	int		ffy;

	int		enemy_x;
	int		enemy_y;
	char	*enemy_path;
	void	*enemy_image;
	int		enemy_count;

	int		exit_x;
	int		exit_y;

	char	*bg_path;
	void	*bg_image;
	char	*col_path;
	void	*col_image;
	char	*wall_path;
	void	*wall_image;
	char	*exit_path;
	void	*exit_image;

	char	**map;
	char	**tmp_map;
	int		map_valid;

	int		randomizer;
	int		width;
	int		height;
	int		animation_count;

	int		tmpx;
	int		tmpy;

	int		col_count;
	int		col_done;
	int		move_count;
}				t_game;

int		image_loop(t_game *game);
char	**split(char const *s, char c, t_game *game);

int		init_map(char *map, t_game *game);
void	floodfill(t_game *game, int x, int y);
void	ft_mapcpy(t_game *game);
int		ft_mapmake(t_game *game);
void	ft_scanmap(t_game *game);

int		exit_game(t_game *game);
int		exit_error(t_game *game);
int		exit_win(t_game *game);
int		exit_killed(t_game *game);

void	go_up(t_game *game);
void	go_down(t_game *game);
void	go_left(t_game *game);
void	go_right(t_game *game);

#endif