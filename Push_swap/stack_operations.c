/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:39:15 by kbrechin          #+#    #+#             */
/*   Updated: 2023/03/02 17:10:43 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


typedef struct s_folder
{
	int				num;
	struct s_folder	*next_node_a;
	struct s_folder	*prev_node_a;
	struct s_folder	*next_node_b;
	struct s_folder	*prev_node_b;
}	t_folder;

void	print_next_folder(t_folder *folder)
{
	t_folder	*next_node_a;
	t_folder	*next_node_b;

	next_node_a = folder->next_node_a;
	next_node_b = folder->next_node_b;
	printf("| STACK_A | STACK_B |\n%d     |    &d\n",
		next_node_a->num, next_node_b->num);
}

int	main(void)
{
	int			i;
	t_folder	start;
	t_folder	new_node;

	start.num = 0;
	start.prev_node_a = NULL;
	for (int i = 10; i > 0; i--)
		add_new_folder(&start);
	new_node.num = 69;
	new_node.prev_node = NULL;
	new_node.next_node = NULL;
	/* swap_folder_data(&start, find_end_folder(&start)); */
	attach_to_end(&start, &new_node);
	print_all_folders(&start);
	/* printf("last folder = %d\n",  find_end_folder(&start)->num ); */
}