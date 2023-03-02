/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:18:13 by kbrechin          #+#    #+#             */
/*   Updated: 2023/03/02 17:09:20 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


typedef struct s_folder
{
	int				num;
	struct s_folder	*next_node_a;
	struct s_folder	*prev_node_a;
	struct s_folder *next_node_b;
	struct s_folder *prev_node_b;
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

void	print_prev_folder(t_folder *folder)
{
	t_folder	*prev_node;

	prev_node = folder->prev_node_a;
	printf("the next folders number = %d\n", prev_node->num);
}

void	add_new_folder(t_folder *folder)
{
	t_folder	*current_node;
	int			i;

	i = 1;
	current_node = folder;
	while (current_node->next_node != NULL)
	{
		i++;
		current_node = current_node->next_node;
	}
	current_node->next_node = malloc(sizeof(t_folder));
	current_node->next_node->prev_node = current_node;
	current_node = current_node->next_node;
	current_node->num = i;
	current_node->next_node = NULL;
}

void	print_all_folders(t_folder *folder)
{
	t_folder	*current_node;

	current_node = folder;
	while (current_node != NULL)
	{
		printf("%d\n", current_node->num);
		current_node = current_node->next_node;
	}
}

t_folder	*find_end_folder(t_folder *folder)
{
	t_folder	*current_node;

	current_node = folder;
	while (current_node->next_node != NULL)
	{
		current_node = current_node->next_node;
	}
	return (current_node);
}

void	swap_folder_data(t_folder *folder_one, t_folder *folder_two)
{
	int	temporary_value;

	temporary_value = folder_one->num;
	folder_one->num = folder_two->num;
	folder_two->num = temporary_value;
}

void	attach_to_end(t_folder *folder_main, t_folder *folder_new)
{
	t_folder	*current_node;

	current_node = find_end_folder(folder_main);
	current_node->next_node = folder_new;
	folder_new->prev_node = current_node;
}

int main(void)
{
	int			i;
	t_folder	start;
	t_folder	new_node;

	start.num = 0;
	start.prev_node = NULL;
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
