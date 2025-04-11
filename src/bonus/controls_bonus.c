/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:37:41 by bpalchet          #+#    #+#             */
/*   Updated: 2025/04/10 19:38:36 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	process_1st_line_r_map(int fd, size_t *first_line_length)
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
	if (!process_1st_line_r_map(fd, &first_line_length))
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
	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	gnl_cleanup(fd);
	close(fd);
	return (line_count);
}

int	create_map_copy(t_game *game, t_flood_data *data)
{
	int	i;
	int	j;

	data->map_copy = (char **)ft_calloc(game->map_height, sizeof(char *));
	if (!data->map_copy)
		return (0);
	i = -1;
	while (++i < game->map_height)
	{
		data->map_copy[i] = ft_strdup(game->map[i]);
		if (!data->map_copy[i])
		{
			j = -1;
			while (++j < i)
				free(data->map_copy[j]);
			free(data->map_copy);
			data->map_copy = NULL;
			return (0);
		}
	}
	return (1);
}
