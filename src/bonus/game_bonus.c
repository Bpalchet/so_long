/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:10:12 by bpalchet          #+#    #+#             */
/*   Updated: 2025/04/10 19:39:33 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "ft_printf/ft_printf.h"

void	check_win_condition(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'E')
	{
		if (game->collectibles == 0)
		{
			ft_printf("Congratulations! You won with %d moves!\n",
				game->moves + 1);
			close_window(game);
			return ;
		}
		else
		{
			printf("You need to collect all collectibles before exiting!\n");
			return ;
		}
	}
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	draw_map(game);
}

void	handle_player_movement(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->collectibles--;
		game->map[new_y][new_x] = '0';
	}
	check_win_condition(game, new_x, new_y);
	if (game->map[new_y][new_x] == 'E' && game->collectibles > 0)
		return ;
	if (new_y < game->player_y)
		game->player_direction = 1;
	else if (new_y > game->player_y)
		game->player_direction = 0;
	else if (new_x < game->player_x)
		game->player_direction = 2;
	else if (new_x > game->player_x)
		game->player_direction = 3;
	update_player_position(game, new_x, new_y);
}

void	move_player(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map_width
		|| new_y < 0 || new_y >= game->map_height)
	{
		ft_printf("Error: New position is out of bounds!\n");
		return ;
	}
	if (game->map[new_y][new_x] == '1')
		return ;
	check_enemy_collision(game, new_x, new_y);
	if (game->game_over)
		return ;
	handle_player_movement(game, new_x, new_y);
}

void	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				game->player_direction = 0;
				return ;
			}
			j++;
		}
		i++;
	}
}
