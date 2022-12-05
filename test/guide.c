#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_dot
{
	int x;
	int y;
	int color;
} t_dot;

typedef struct s_program {
	void	*mlx_pointer;
	void	*window;
	t_data	*img;
	t_data	*wallpaper;
	t_dot	*dot;
	int		dotNum;
	
}			t_program;

struct s_window
{
	int		width;
	int		height;
	char	*name;
};



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//struct s_window t_window = {1920, 1080, "Hello world!"};

int	keypress(int keycode, t_program	*address)
{
	printf("key pressed id is = %d\n", keycode);
	if (keycode == 65307 || keycode == 53){
		mlx_destroy_window(address->mlx_pointer, address->window);
		exit(0);
	}
	return (0);
}

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int	pixel_get(t_data *r, int x, int y)
{
	char	*dst;

	dst = r->addr + (y * r->line_length + x * (r->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int frame(t_program *a)
{
	(void)a;
	static int x = 500;
	static int y = 500;
	static double dir = 0;
	//static int color = 0x00000100;

	// get mouse position
	// mlx_mouse_get_pos(a->window, &x, &y);
	// printf("%d , %d\n", x, y);

	x += cos(dir) * 80;
	y += sin(dir) * 80;

	dir = (rand() % 400) * 3.14 / 180;

	if ( !(35 < x && x < 1900 && 35 < y && y < 1000))
	{
		x = 1920 / 2;
		y = 1800 / 2;
	}
	
	//jamie made wierd dots
	for (int i = 0; i < a->dotNum; i++)
	{
		dir = (rand() % 3) * 120 * 3.14 / 180;
		a->dot[i].x += cos(dir) * 10;
		a->dot[i].y += sin(dir) * 10;
		if (a->dot[i].x > 1920 || a->dot[i].x < 0 || a->dot[i].y > 1080 || a->dot[i].y < 0)
		{
			a->dot[i].x = 1920 / 2;
			a->dot[i].y = 1080 / 2;
		}
		my_mlx_pixel_put(a->wallpaper, a->dot[i].x, a->dot[i].y, a->dot[i].color);
	}
	int col;
	//reset window image so clears after image
	for (int i = 0; i < 1920; i++)
	{
		for (int j = 0; j < 1080; j++)
		{
			col = pixel_get(a->wallpaper, i, j) / 1.5;
			my_mlx_pixel_put(a->wallpaper, i, j, col);
		}
	}
	// the image to run with the code
	mlx_put_image_to_window(a->mlx_pointer, a->window,  a->wallpaper->img, 0, 0);
	//mlx_put_image_to_window(a->mlx_pointer, a->window,  a->img, x, y);
	return 0;
}

int	main(void)
{
	
	t_program address;
	//amount of dots
	address.dotNum = 100000;
	struct s_window t_window = {1920, 1080, "Hello world!"};
	//changes the colour and spawn position of the dots
	address.dot = malloc(sizeof(t_dot) * address.dotNum);
	for (int i = 0; i < address.dotNum; i++)
	{
		address.dot[i].x = 1920 / 2;
		address.dot[i].y = 1080 / 2;
		address.dot[i].color = rand();
	}
	//creates an important value for the functions to operate successfully 
	address.mlx_pointer = mlx_init();
	//makes a window of height and width area on screen with a given name
	address.window = mlx_new_window(address.mlx_pointer, t_window.width, t_window.height, t_window.name);
	//hooks allow execute functions with certain events eg. keypress
	mlx_hook(address.window, 2, 1L<<0, keypress, &address);
	
	t_data	*img;
	t_data	wimg;
	wimg.img = mlx_new_image(&address.mlx_pointer, 1920, 1080);
	wimg.addr = mlx_get_data_addr(wimg.img, &wimg.bits_per_pixel, &wimg.line_length,
								&wimg.endian);
	img = mlx_xpm_file_to_image(&address.mlx_pointer, "./img/fish.xpm", &t_window.width, &t_window.height);

	address.img = img;
	address.wallpaper = &wimg;
	//keeps program running, window open and runs functions above
	mlx_loop_hook(address.mlx_pointer, frame, &address);
	
	mlx_loop(address.mlx_pointer);
} 
