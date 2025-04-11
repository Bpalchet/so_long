/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:25:52 by bpalchet          #+#    #+#             */
/*   Updated: 2025/04/10 19:47:30 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free (line);
		line = get_next_line(fd);
	}
}

void	cleanup_and_exit(t_game *game, const char *message)
{
	if (game && game->map)
		free_map(game);
	ft_printf("%s\n", message);
	exit(1);
}

void	exit_with_error(const char *message)
{
	ft_printf("%s\n", message);
	exit(1);
}

int	check_file_extension(const char *filename)
{
	const char	*dot;

	dot = ft_strrchr(filename, '.');
	if (!dot || dot == filename)
		return (0);
	return (ft_strncmp(dot, ".ber", 5) == 0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	initialize_map(&game);
	if (argc != 2)
	{
		ft_printf("Usage: %s <path/map_file.ber>\n", argv[0]);
		return (1);
	}
	if (!check_file_extension(argv[1]))
	{
		ft_printf("Error: Map file must have .ber extension\n");
		return (1);
	}
	parse_map(&game, argv[1]);
	initialize_window(&game);
	return (0);
}
