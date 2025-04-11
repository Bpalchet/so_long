/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:26:56 by bpalchet          #+#    #+#             */
/*   Updated: 2025/04/01 19:14:48 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_tile(t_game *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.wall,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.floor,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.collectible, j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->textures.exit,
			j * TILE_SIZE, i * TILE_SIZE);
	else if (game->map[i][j] == 'M')
	{
		if (game->enemy_frame == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->textures.enemy1,
				j * TILE_SIZE, i * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->textures.enemy2,
				j * TILE_SIZE, i * TILE_SIZE);
	}
}

void	draw_player(t_game *game, int i, int j)
{
	if (game->player_direction == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_front, j * TILE_SIZE, i * TILE_SIZE);
	else if (game->player_direction == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_back, j * TILE_SIZE, i * TILE_SIZE);
	else if (game->player_direction == 2)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_left, j * TILE_SIZE, i * TILE_SIZE);
	else if (game->player_direction == 3)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_right, j * TILE_SIZE, i * TILE_SIZE);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.player_front, j * TILE_SIZE, i * TILE_SIZE);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			draw_tile(game, i, j);
			if (game->map[i][j] == 'P')
				draw_player(game, i, j);
		}
	}
}

int	render_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	draw_moves_counter(game);
	animate_enemies(game);
	return (0);
}
