/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:31:22 by bpalchet          #+#    #+#             */
/*   Updated: 2025/03/29 16:04:33 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf/ft_printf.h"

void	initialize_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_with_error("Error: Failed to initialize MIniLibx");
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "So Long");
	if (!game->win)
	{
		free(game->mlx);
		exit_with_error("Error: Failed to create window");
	}
	load_textures(game);
	draw_map(game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_press, game);
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
}

void	initialize_map(t_game *game)
{
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = -1;
	game->player_y = -1;
	game->collectibles = 0;
	game->moves = 0;
}

void	count_collectibles(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->collectibles = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'C')
				game->collectibles++;
			j++;
		}
		i++;
	}
}

void	load_player_textures(t_game *game)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	game->textures.player_front = mlx_xpm_file_to_image(game->mlx,
			"textures/player_front.xpm", &width, &height);
	game->textures.player_back = mlx_xpm_file_to_image(game->mlx,
			"textures/player_back.xpm", &width, &height);
	game->textures.player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/player_left.xpm", &width, &height);
	game->textures.player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/player_right.xpm", &width, &height);
	if (!game->textures.player_front || !game->textures.player_back
		|| !game->textures.player_left || !game->textures.player_right)
		exit_with_error("Error: Failed to load player textures");
}

void	load_textures(t_game *game)
{
	int	width;
	int	height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &width, &height);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &width, &height);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &width, &height);
	if (!game->textures.wall || !game->textures.floor
		|| !game->textures.collectible || !game->textures.exit)
		exit_with_error("Error: Failed to load room textures");
	load_player_textures(game);
}
