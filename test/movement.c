/* this tracks the key presses in the terminal 
	so all that need to be done is setting W,A,S and D
	for their respective direction of movement.*/
// cant move into walls
// number of moves must be displayed
// pressing esc must close the window and quit the program (DONE)
// Clicking on the cross on the window’s frame must close the window and quit the program in a clean way
int	keypress(int keycode, t_program	*address)
{
	printf("key pressed id is = %d\n", keycode);
	if (keycode == 65307 || keycode == 53){
		mlx_destroy_window(address->mlx_pointer, address->window);
		exit(1);
	}
	return (1);
}