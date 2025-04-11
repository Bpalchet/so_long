/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpalchet <bpalchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:26:45 by bpalchet          #+#    #+#             */
/*   Updated: 2025/04/09 19:30:55 by bpalchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

# define TILE_SIZE 64
# define WINDOW_TITLE "So long"

typedef struct s_flood_data
{
	char	**map_copy;
	int		collectibles;
	int		exit_reachable;
}	t_flood_data;

typedef struct s_textures
{
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
	void	*player_front;
	void	*player_back;
	void	*player_left;
	void	*player_right;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			map_width;
	int			map_height;
	char		**map;
	int			player_x;
	int			player_y;
	int			collectibles;
	int			moves;
	int			player_direction;
	t_textures	textures;
}	t_game;

// Funzioni principali di gestione mappa
int		check_file_extension(const char *filename);
void	initialize_window(t_game *game);
void	parse_map(t_game *game, char *map_file);
void	free_map(t_game *game);
int		process_first_line_r_map(int fd, size_t *first_line_length);
int		check_remaining_lines_r_map(int fd, size_t first_line_length);
int		right_map_file(char *map_file);
int		validate_map(t_game *game);
void	resize_map(t_game *game, int *max_lines, char ***temp_map);
void	read_map_file(t_game *game, char *map_file);
void	initialize_map(t_game *game);
int		check_border(t_game *game, int i, int j);
int		count_map_elements(t_game *game, int *p, int *e, int *c);
int		validate_elements_count(t_game *game, int p, int e, int c);
void	ft_check_elements(t_game *game, int i, int j);
void	free_gnl(int fd);

// Funzioni di rendering
void	load_textures(t_game *game);
void	load_player_textures(t_game *game);
void	cleanup_textures(t_game *game);
void	draw_map(t_game *game);
int		render_frame(t_game *game);
int		open_map_file(char *map_file);
void	process_first_line(t_game *game, char **line, int fd);
void	read_remaining_lines(t_game *game, int fd, int *current_lines);
void	draw_tile(t_game *game, int i, int j);
void	draw_player(t_game *game, int i, int j);

// Funzioni di gestione degli eventi
int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);

// Funzioni di gioco
void	move_player(t_game *game, int new_x, int new_y);
void	check_win_condition(t_game *game, int new_x, int new_y);
void	find_player_position(t_game *game);
void	count_collectibles(t_game *game);
void	update_player_position(t_game *game, int new_x, int new_y);
void	handle_player_movement(t_game *game, int new_x, int new_y);

// Funzioni di utilità
void	exit_with_error(const char *message);
void	cleanup_and_exit(t_game *game, const char *message);
int		validate_path(t_game *game);
void	flood_fill(int x, int y, t_flood_data *data);
int		count_lines_in_file(char *map_file);
int		create_map_copy(t_game *game, t_flood_data *data);
int		check_flood_results(t_game *game, t_flood_data *data);
void	cleanup_map_copy(t_flood_data *data, int height);

#endif
