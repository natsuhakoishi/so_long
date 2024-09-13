/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 00:52:00 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/09/04 16:46:18 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(t_game *game)
{
	game->player_y -= 64;
	if (game->map[game->player_y / 64][game->player_x / 64] == 'E' && \
		game->col_count == game->col_done)
		exit_win(game);
	else if (game->map[game->player_y / 64][game->player_x / 64] == 'C')
	{
		++game->col_done;
		game->map[game->player_y / 64][game->player_x / 64] = '0';
	}
	++game->move_count;
}

void	go_down(t_game *game)
{
	game->player_y += 64;
	if (game->map[game->player_y / 64][game->player_x / 64] == 'E' && \
		game->col_count == game->col_done)
		exit_win(game);
	else if (game->map[game->player_y / 64][game->player_x / 64] == 'C')
	{
		++game->col_done;
		game->map[game->player_y / 64][game->player_x / 64] = '0';
	}
	++game->move_count;
}

void	go_left(t_game *game)
{
	game->player_x -= 64;
	if (game->map[game->player_y / 64][game->player_x / 64] == 'E' && \
		game->col_count == game->col_done)
		exit_win(game);
	else if (game->map[game->player_y / 64][game->player_x / 64] == 'C')
	{
		++game->col_done;
		game->map[game->player_y / 64][game->player_x / 64] = '0';
	}
	++game->move_count;
}

void	go_right(t_game *game)
{
	game->player_x += 64;
	if (game->map[game->player_y / 64][game->player_x / 64] == 'E' && \
		game->col_count == game->col_done)
		exit_win(game);
	else if (game->map[game->player_y / 64][game->player_x / 64] == 'C')
	{
		++game->col_done;
		game->map[game->player_y / 64][game->player_x / 64] = '0';
	}
	++game->move_count;
}
