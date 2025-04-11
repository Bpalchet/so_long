/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:08:12 by bpalchet          #+#    #+#             */
/*   Updated: 2025/04/09 19:03:08 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

int	open_map_file(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		exit_with_error("Error: Could not open map file");
	return (fd);
}

void	process_first_line(t_game *game, char **line, int fd)
{
	*line = get_next_line(fd);
	if (!*line)
	{
		close(fd);
		cleanup_and_exit(game, "Error: Empty map file");
	}
	game->map_width = ft_strlen(*line) - 1;
	if ((*line)[game->map_width] == '\n')
		(*line)[game->map_width] = '\0';
}

void	read_remaining_lines(t_game *game, int fd, int *current_lines)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) != (size_t)game->map_width)
		{
			free(line);
			free_gnl(fd);
			close(fd);
			cleanup_and_exit(game,
				"Error: Map lines have inconsistent lengths");
		}
		game->map[*current_lines] = line;
		(*current_lines)++;
		line = get_next_line(fd);
	}
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

void	cleanup_map_copy(t_flood_data *data, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		free(data->map_copy[i]);
	free(data->map_copy);
}
