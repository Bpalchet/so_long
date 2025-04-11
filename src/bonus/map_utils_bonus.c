/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:08:12 by bpalchet          #+#    #+#             */
/*   Updated: 2025/04/11 17:11:44 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

int	check_file_extension(const char *filename)
{
	const char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (0);
	return (ft_strncmp(dot, ".ber", 5) == 0);
}

int	open_map_file(char *map_file)
{
	int	dir_fd;
	int	fd;

	dir_fd = open(map_file, __O_DIRECTORY);
	if (dir_fd >= 0)
	{
		close (dir_fd);
		exit_with_error("Error: expected a file, not a directory");
	}
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
		exit_with_error("Error: Empty map file");
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

void	cleanup_textures(t_game *game)
{
	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	if (game->textures.collectible)
		mlx_destroy_image(game->mlx, game->textures.collectible);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->textures.player_front)
		mlx_destroy_image(game->mlx, game->textures.player_front);
	if (game->textures.player_back)
		mlx_destroy_image(game->mlx, game->textures.player_back);
	if (game->textures.player_left)
		mlx_destroy_image(game->mlx, game->textures.player_left);
	if (game->textures.player_right)
		mlx_destroy_image(game->mlx, game->textures.player_right);
	if (game->textures.enemy1)
		mlx_destroy_image(game->mlx, game->textures.enemy1);
	if (game->textures.enemy2)
		mlx_destroy_image(game->mlx, game->textures.enemy2);
}
