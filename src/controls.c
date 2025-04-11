/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:37:41 by bpalchet          #+#    #+#             */
/*   Updated: 2025/04/09 19:30:38 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	process_first_line_r_map(int fd, size_t *first_line_length)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		exit_with_error("Error: Empty map file");
	}
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	*first_line_length = ft_strlen(line);
	free(line);
	return (1);
}

int	check_remaining_lines_r_map(int fd, size_t first_line_length)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) != first_line_length)
		{
			free(line);
			free_gnl(fd);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	right_map_file(char *map_file)
{
	int		fd;
	size_t	first_line_length;

	fd = open_map_file(map_file);
	if (!process_first_line_r_map(fd, &first_line_length))
		return (0);
	if (!check_remaining_lines_r_map(fd, first_line_length))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	count_lines_in_file(char *map_file)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_with_error("Error: Could not open map file");
	line = get_next_line(fd);
	line_count = 0;
	while (line)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

int	validate_path(t_game *game)
{
	t_flood_data	data;

	data.collectibles = 0;
	data.exit_reachable = 0;
	if (!create_map_copy(game, &data))
		exit_with_error("Error: Failed to create map copy");
	flood_fill(game->player_x, game->player_y, &data);
	return (check_flood_results(game, &data));
}
