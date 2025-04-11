/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:31:48 by bpalchet          #+#    #+#             */
/*   Updated: 2025/04/10 19:36:31 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_moves_counter(t_game *game)
{
	char	*moves_str;
	char	*prefix;

	prefix = "Moves: ";
	moves_str = ft_itoa(game->moves);
	if (!moves_str)
		return ;
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, prefix);
	mlx_string_put(game->mlx, game->win, 70, 20, 0xFFFFFF, moves_str);
	free(moves_str);
}

void	animate_enemies(t_game *game)
{
	static int	frame;
	int			animation_delay;

	animation_delay = 2000;
	frame = (frame + 1) % (2 * animation_delay);
	game->enemy_frame = (frame >= animation_delay);
}

void	check_enemy_collision(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'M')
	{
		game->game_over = 1;
		mlx_string_put(game->mlx, game->win,
			game->map_width * TILE_SIZE / 2 - 50,
			game->map_height * TILE_SIZE / 2, 0xFF0000,
			"You lose! Enemy touched you!");
		ft_printf("You lose! Enemy touched you!\n");
		mlx_do_sync(game->mlx);
		sleep(3);
		close_window(game);
	}
}

void	gnl_cleanup(int fd)
{
	char	*line;
	char	*temp;

	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		line = NULL;
	}
	temp = get_next_line(-1);
	if (temp != NULL)
	{
		free(temp);
		temp = NULL;
	}
}

int	check_path_with_enemies(t_game *game, t_flood_data *data)
{
	int	result;
	int	i;
	int	j;

	if (!create_map_copy(game, data))
		return (0);
	data->collectibles = 0;
	data->exit_reachable = 0;
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
			if (data->map_copy[i][j] == 'M')
				data->map_copy[i][j] = '1';
	}
	flood_fill(game->player_x, game->player_y, data);
	result = check_flood_results(game, data);
	cleanup_map_copy(data, game->map_height);
	return (result);
}
