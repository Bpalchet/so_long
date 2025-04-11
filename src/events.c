/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:44:26 by bpalchet          #+#    #+#             */
/*   Updated: 2025/04/09 18:34:23 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	cleanup_textures(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game);
	exit (0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 65307)
		close_window(game);
	else if (keycode == 119 || keycode == 115
		|| keycode == 97 || keycode == 100)
	{
		if (keycode == 119)
			new_y--;
		else if (keycode == 115)
			new_y++;
		else if (keycode == 97)
			new_x--;
		else if (keycode == 100)
			new_x++;
		move_player(game, new_x, new_y);
		render_frame(game);
	}
	return (0);
}

int	check_flood_results(t_game *game, t_flood_data *data)
{
	int	result;

	result = (data->collectibles == game->collectibles && data->exit_reachable);
	cleanup_map_copy(data, game->map_height);
	return (result);
}

void	flood_fill(int x, int y, t_flood_data *data)
{
	if (data->map_copy[y][x] == '1')
		return ;
	if (data->map_copy[y][x] == 'E')
	{
		data->map_copy[y][x] = 'X';
		data->exit_reachable = 1;
		return ;
	}
	if (data->map_copy[y][x] == '1' || data->map_copy[y][x] == 'X')
		return ;
	if (data->map_copy[y][x] == 'C')
		data->collectibles++;
	data->map_copy[y][x] = 'X';
	flood_fill(x + 1, y, data);
	flood_fill(x - 1, y, data);
	flood_fill(x, y + 1, data);
	flood_fill(x, y - 1, data);
}
