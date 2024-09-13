/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 22:07:35 by yyean-wa          #+#    #+#             */
/*   Updated: 2024/09/09 15:55:50 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	while (game->height >= 0)
	{
		free(game->map[game->height]);
		--game->height;
	}
	free(game->map);
	write(1, "\nStarry Exit.\n\n", 15);
	exit(0);
	return (0);
}

int	exit_error(t_game *game)
{
	while (game->height >= 0)
	{
		free(game->map[game->height]);
		--game->height;
	}
	free(game->map);
	write(1, "\nError.\nStarry Map Error.\n\n", 27);
	exit(0);
	return (0);
}

int	exit_win(t_game *game)
{
	while (game->height >= 0)
	{
		free(game->map[game->height]);
		--game->height;
	}
	free(game->map);
	write(1, "\nRYO WIN !!!\n\n", 14);
	exit(0);
	return (0);
}

int	exit_killed(t_game *game)
{
	while (game->height >= 0)
	{
		free(game->map[game->height]);
		--game->height;
	}
	free(game->map);
	write(1, "\nGame Over.\nRyo got caught by Nijika.\n\n", 39);
	exit(0);
	return (0);
}
