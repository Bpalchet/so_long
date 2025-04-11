/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:18:31 by bpalchet          #+#    #+#             */
/*   Updated: 2025/04/09 19:08:46 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

int	check_border(t_game *game, int i, int j)
{
	if ((i == 0 || i == game->map_height - 1 || j == 0
			|| j == game->map_width - 1) && game->map[i][j] != '1')
		return (0);
	return (1);
}

void	ft_check_elements(t_game *game, int i, int j)
{
	if (game->map[i][j] != 'P' && game->map[i][j] != 'E' &&
			game->map[i][j] != 'C' && game->map[i][j] != '0' &&
			game->map[i][j] != '1')
	{
		free_map(game);
		exit_with_error("Map Error: Wrong elements inside map.");
	}
}

int	count_map_elements(t_game *game, int *p, int *e, int *c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		if (ft_strlen(game->map[i]) != (size_t)game->map_width)
			cleanup_and_exit(game, "Map Error: Inconsistent line lengths");
		j = -1;
		while (++j < game->map_width)
		{
			if (!check_border(game, i, j))
				return (0);
			ft_check_elements(game, i, j);
			if (game->map[i][j] == 'P')
				(*p)++;
			else if (game->map[i][j] == 'E')
				(*e)++;
			else if (game->map[i][j] == 'C')
				(*c)++;
		}
	}
	return (1);
}

int	validate_elements_count(t_game *game, int p, int e, int c)
{
	if (p != 1)
	{
		cleanup_and_exit(game, "Map Error: Player Missing or more than one");
		return (0);
	}
	if (e != 1)
	{
		cleanup_and_exit(game, "Map Error: Exit Missing or more than one");
		return (0);
	}
	if (c < 1)
	{
		cleanup_and_exit(game, "Map Error: No collectibles");
		return (0);
	}
	return (1);
}
