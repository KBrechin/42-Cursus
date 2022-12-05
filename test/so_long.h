#ifndef SO_LONG_H
 #define SO_LONG_H

//# include "libft/libft.h"
# include <stdio.h>
#include <unistd.h>
# include <stdlib.h>
# include "../minilibx/mlx.h"

# define IMG_SIZE 64

typedef struct s_vector{
	int	x;
	int y;
} t_vector;

/*typedef enum s_maptiles{
	WALL = '1',
	SPACE = '0',
	PLAYER = 'P',
	ITEM = 'C',
	EXIT = 'E'
} t_maptiles;*/

typedef enum s_keycode{
	ESC = 53,
	KEY_NORTH = 13,
	KEY_SOUTH = 1,
	KEY_EAST = 2,
	KEY_WEST = 0,
} t_keycode;

typedef struct s_player{
	void *player_img;
	t_vector	position;
}t_player;

typedef struct s_tile{
	void	*ground;
}	t_tile;


typedef struct s_game{
	void		*mlx;
	void		*window;
	int			bits_per_pixel;
	int			line_length;
	void		*pointer;
	t_vector 	win_size;
	t_keycode 	keys;
	t_player	player;
	t_vector	img_size;
	t_tile		tile;
} t_game;

int		inputs(int key, t_game *game);
int 	destroy_program(t_game *game);
void	open_images(t_game *game);
int 	draw(t_game game);
void	game_init(t_game *game);

#endif