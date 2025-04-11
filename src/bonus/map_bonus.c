/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:22:42 by bpalchet          #+#    #+#             */
/*   Updated: 2025/04/10 19:41:19 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

void	resize_map(t_game *game, int *max_lines, char ***temp_map)
{
	int	i;

	*max_lines *= 2;
	*temp_map = (char **)ft_calloc(*max_lines, sizeof(char *));
	if (!*temp_map)
	{
		free_map(game);
		exit_with_error("Error: Failed to allocate memory for map");
	}
	i = 0;
	while (i < game->map_height)
	{
		(*temp_map)[i] = game->map[i];
		i++;
	}
	free(game->map);
	game->map = *temp_map;
}

void	read_map_file(t_game *game, char *map_file)
{
	char	*line;
	int		current_lines;
	int		line_count;
	int		fd;

	current_lines = 0;
	if (!right_map_file(map_file))
		cleanup_and_exit(game, "Error: Map lines have inconsistent lengths");
	line_count = count_lines_in_file(map_file);
	if (line_count <= 0)
		exit_with_error("Error: Empty map file");
	game->map = (char **)ft_calloc(line_count + 1, sizeof(char *));
	if (!game->map)
		exit_with_error("Error: Failed to allocate memory for map");
	fd = open_map_file(map_file);
	process_first_line(game, &line, fd);
	game->map[current_lines++] = line;
	read_remaining_lines(game, fd, &current_lines);
	game->map_height = current_lines;
	close(fd);
}

void	parse_map(t_game *game, char *map_file)
{
	int	i;

	i = 0;
	initialize_map(game);
	read_map_file(game, map_file);
	while (i < game->map_height)
	{
		if (!game->map[i])
		{
			free_map(game);
			exit_with_error("Error: Failed to read map line");
		}
		i++;
	}
	find_player_position(game);
	count_collectibles(game);
	if (!validate_map(game))
	{
		free_map(game);
		exit_with_error("Error: Invalid map configuration");
	}
}

void	free_map(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->map_height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
		game->map = NULL;
	}
}

int	validate_map(t_game *game)
{
	int	player_count;
	int	exit_count;
	int	collectible_count;

	player_count = 0;
	collectible_count = 0;
	exit_count = 0;
	if (!count_map_elements(game, &player_count, &exit_count,
			&collectible_count))
		return (0);
	if (!validate_elements_count(game, player_count, exit_count,
			collectible_count))
		return (0);
	if (!validate_path(game))
		return (0);
	return (1);
}
