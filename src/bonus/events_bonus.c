/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:44:26 by bpalchet          #+#    #+#             */
/*   Updated: 2025/04/10 19:39:00 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	flood_fill(int x, int y, t_flood_data *data)
{
	if (data->map_copy[y][x] == '1' || data->map_copy[y][x] == 'M')
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

int	check_flood_results(t_game *game, t_flood_data *data)
{
	return (data->collectibles == game->collectibles && data->exit_reachable);
}

int	validate_path(t_game *game)
{
	t_flood_data	data;
	int				valid;

	data.collectibles = 0;
	data.exit_reachable = 0;
	if (!create_map_copy(game, &data))
		exit_with_error("Error: Failed to create map copy");
	flood_fill(game->player_x, game->player_y, &data);
	valid = check_flood_results(game, &data);
	cleanup_map_copy(&data, game->map_height);
	if (!valid)
	{
		cleanup_and_exit(game,
			"Error: Map has unreachable collectibles or exit");
		return (0);
	}
	if (!check_path_with_enemies(game, &data))
	{
		cleanup_and_exit(game, "Error: Enemies block collectibles or exit");
		return (0);
	}
	return (1);
}
