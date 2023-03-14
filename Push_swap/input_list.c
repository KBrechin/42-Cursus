/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:22:14 by kbrechin          #+#    #+#             */
/*   Updated: 2023/03/14 15:42:17 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_folder
{
	int				num;
	struct s_folder	*next_node_a;
	struct s_folder	*prev_node_a;
	//struct s_folder *next_node_b;
	//struct s_folder *prev_node_b;
}	t_folder;

void	print_all_folders(t_folder *folder)
{
	t_folder	*current_node;

	current_node = folder;
	while (current_node != NULL)
	{
		printf("%d\n", current_node->num);
		current_node = current_node->next_node_a;
	}
}

t_folder	*find_end_folder(t_folder *folder)
{
	t_folder	*current_node;

	current_node = folder;
	while (current_node->next_node_a != NULL)
	{
		current_node = current_node->next_node_a;
	}
	return (current_node);
}

void	attach_to_end(t_folder *folder_main, t_folder *folder_new)
{
	t_folder	*current_node;

	current_node = find_end_folder(folder_main);
	current_node->next_node_a = folder_new;
	folder_new->prev_node_a = current_node;
}

void	add_new_folder(t_folder *folder, int i)
{
	t_folder	*current_node;

	current_node = folder;
	/* searches for the last folder in the linked list*/
	while (current_node->next_node_a != NULL)
	{
		/*iterates through the list by using the next node address*/
		current_node = current_node->next_node_a;
	}
	print_all_folders(folder);
	printf("\n");
	/*dedicates memory for the next node at the size of the linked list*/
	current_node->next_node_a = malloc(sizeof(t_folder));
	/*links the next node to the previous node*/
	current_node->next_node_a->prev_node_a = current_node;
	/*the current node changes value to the next node*/
	current_node = current_node->next_node_a;
	/*the new node changes value to that of i*/
	current_node->num = i;
	/*links the final node end to NULL*/
	current_node->next_node_a = NULL;
}

t_folder	initialise_stack_a(int argc, char **argv)
{
	t_folder	new_node;
	t_folder	start;
	int			i;

	i = 2;
	start.num = atoi(argv[1]);
	start.prev_node_a = NULL;
	while (i < argc)
	{
		add_new_folder(&start, atoi(argv[i]));
		i++;
	}
	new_node.num = 69;
	new_node.prev_node_a = NULL;
	new_node.next_node_a = NULL;
	attach_to_end(&start, &new_node);
	//print_all_folders(&start);
	print_all_folders(&start);
	return (start);
}

int	main(int argc, char **argv)
{
	t_folder	stack_a;
	// t_folder	new_node;
	//int 		i = 0;

	//printf("%d\n" , i++);
	stack_a = initialise_stack_a(argc, argv);
	// int			i;

	// i = 2;
	// start.num = atoi(argv[1]);
	// start.prev_node_a = NULL;
	// while (i < argc)
	// {
	// 	add_new_folder(&start, atoi(argv[i]));
	// 	i++;
	// }
	// new_node.num = 69;
	// new_node.prev_node_a = NULL;
	// new_node.next_node_a = NULL;
	// attach_to_end(&stack_a, &new_node);
	// print_all_folders(&start);
	// print_all_folders(&stack_a);
}
