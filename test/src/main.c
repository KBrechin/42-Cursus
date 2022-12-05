/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:18:32 by kbrechin          #+#    #+#             */
/*   Updated: 2022/12/05 19:13:19 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../so_long.h"

int destroy_program(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
}

void update_map(t_game *game)
{
	int x;
	int y;

	x = game->player.position.x;
	y = game->player.position.y;
	if (game->map[y][x] == 'C')
	{	
		game->coins--;
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == 'E' && game->coins == 0)
		exit(1);
	if (game->map[game->last_y][game->last_x] == 'E')
		mlx_put_image_to_window(game->mlx, game->window, 
		game->tile.exit, game->last_x * 64, game->last_y * 64);
	else
		mlx_put_image_to_window(game->mlx, game->window, 
		game->tile.ground, game->last_x * 64, game->last_y * 64);
	mlx_put_image_to_window(game->mlx, game->window, 
	game->player.player_img, game->player.position.x * 64, game->player.position.y * 64);
	game->last_x = game->player.position.x;
	game->last_y = game->player.position.y;
	printf("moves = %d\n", game->movies++);
}

// void	swap_chars(char player, char tile)
// {
// 	if (tile == 1)
// 		return ;
// 	if (tile == 'C')
// 		game->coins--;
// 	if (tile == 'E')
// 		exit();
// 	else
// 	{
// 		swp
// 	}
	
// }

int inputs(int key, t_game *game)
{
	int x;
	int y;

	x = game->player.position.x;
	y = game->player.position.y;
	if (key == ESC)
		destroy_program(game);
	if (key == KEY_NORTH && game->map[y - 1][x] != '1')
		game->player.position.y -= 1;
	if (key == KEY_SOUTH && game->map[y + 1][x] != '1')
		game->player.position.y += 1;
	if (key == KEY_EAST && game->map[y][x + 1] != '1')
		game->player.position.x += 1;;
	if (key == KEY_WEST && game->map[y][x - 1] != '1')
		game->player.position.x -= 1;
	update_map(game);
	return (0);
}

void open_player_img(t_game *game){
	game->player.player_img = mlx_xpm_file_to_image(game->mlx,
	 "../img/fish.xmp", &game->img_size.x, &game->img_size.y);
}

// int	frame(t_game *game)
// {
// 	(void) game;
// 	return (1);
// }

void map_importer(t_game *game, char *path)
{
	int i;
	int fd;

	i = 0;
	fd = open(path, O_RDONLY);
	game->map = malloc(sizeof(char *) * 100);
	while (1)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i] == NULL)
			break ;
		i++;
	}
	game->map_h = i;
	game->map_w = ft_strlen(game->map[0]) - 1;
}

void	draw_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->window, 
		game->tile.ground, x * 64, y * 64);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->window, 
		game->tile.wall, x * 64, y * 64);
	else if(game->map[y][x] == 'P')
	{
		game->player.position.x = x;
		game->player.position.y = y;
		game->last_x = game->player.position.x;
		game->last_y = game->player.position.y;
		mlx_put_image_to_window(game->mlx, game->window, 
		game->player.player_img, game->player.position.x * 64, game->player.position.y * 64);
	}
	else if(game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window, 
		game->tile.coin, x * 64, y * 64);
		game->coins++;
	}
	else if(game->map[y][x] == 'E'){
		mlx_put_image_to_window(game->mlx, game->window, 
		game->tile.exit, x * 64, y * 64);
	}

}

int	main(void)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	game->coins = 0;
	game->movies = 0;
	map_importer(game, "./map/1.ber");

	game->win_size.x = game->map_w * 64;
	game->win_size.y = game->map_h * 64;
	

	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->win_size.x, game->win_size.y, "so_long");
	
	int h, w;
	game->player.player_img = mlx_xpm_file_to_image(&game->mlx, "./img/fish.xpm", &h, &w);
	game->tile.ground = mlx_xpm_file_to_image(&game->mlx, "./img/ground.xpm", &h, &w);
	game->tile.coin = mlx_xpm_file_to_image(&game, "./img/plant_01.xpm", &h, &w);
	game->tile.wall = mlx_xpm_file_to_image(&game, "./img/wall.xpm", &h, &w);
	game->tile.exit = mlx_xpm_file_to_image(&game, "./img/exit.xpm", &h, &w);

	int x;
	int y;

	y = 0;
	while (y < game->map_h )
	{
		x = 0;
		while (x < game->map_w)
		{
			draw_map(game, x, y);
			x++;
		}
		printf("\n");
		y++;
	}
	mlx_hook(game->window, 2, 0, inputs, game);
	mlx_loop(game->mlx);
}
