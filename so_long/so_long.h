/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:09:54 by kbrechin          #+#    #+#             */
/*   Updated: 2023/01/08 17:07:05 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../minilibx/mlx.h"

# define IMG_SIZE 64

typedef struct s_vector{
	int	x;
	int	y;
}	t_vector;

typedef enum s_keycode{
	ESC = 53,
	UP_KEY = 13,
	DOWN_KEY = 1,
	RIGHT_KEY = 2,
	LEFT_KEY = 0,
}	t_keycode;

typedef struct s_player{
	void		*p_img;
	t_vector	position;
}t_player;

typedef struct s_tile{
	void	*ground;
	void	*coin;
	void	*wall;
	void	*exit;
}	t_tile;


typedef struct s_game{
	void		*mlx;
	void		*window;
	int			bits_per_pixel;
	int			line_length;
	int			last_x;
	int			last_y;
	char		**map;
	int			map_h;
	int			map_w;
	int			coins;
	int			movies;
	int			current_coins;
	int			current_exits;
	t_vector	win_size;
	t_keycode	keys;
	t_player	player;
	t_vector	img_size;
	t_tile		tile;
}	t_game;

// all
int		ft_printf(const char *str, ...);

// map.c
void	update_map(t_game *game);
void	map_importer(t_game *game, char *path);
void	draw_map(t_game *game, int x, int y);
void	set_map(t_game *game);
int	check_map(t_game *game);

// main.c
int		inputs(int key, t_game *game);
void	open_images(t_game *game);
void	game_init(t_game *game);
char	*get_next_line(int fd);
char	*ft_substr(const char *str, size_t start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *start, char *end);

// flood_fill.c
char	**copy_map(t_game *game);
void	mark(int x, int y, char **map, t_game *game);
int		is_walkable(int x, int y, char **map);
int		scan_directions(int x, int y, char **map, t_game *game);
void	scanner(t_game *game, char **map);
int		flood_fill(t_game *game);

//utils.c
int		destroy_program(t_game *game);
void	free_map(char **map, t_game *game);
void	put_num(int num);
void	player_pos(t_game *game, int direction);

// mlx_string_put(game->mlx, game->window, 50, 50, 0x00FFFFFF, "hello world");

#endif