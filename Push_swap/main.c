/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:15:51 by kbrechin          #+#    #+#             */
/*   Updated: 2023/02/19 15:29:08 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_Node
{
	int			data;
	struct Node	*temp;
	struct Node	*next;
	struct Node	*prev;
}	t_Node;
t_Node	*top = NULL;

void	push(int value, t_Node *Node)
{
	Node = (struct Node *)malloc(sizeof(Node));
	Node->data = value; // assign value to the node
	if (top == NULL)
	{
		Node->next = NULL;
	}
	else
	{
		Node->next = top; // Make the node as top
	}
	top = Node; // top always points to the newly created node
	printf("Node is Inserted\n\n");
}

void	display(t_Node *Node)
{
	struct Node->temp = next;
    // Display the elements of the stack
    if (top == NULL)
	{
		printf("\nStack Underflow\n");
	}
	else
	{
		printf("The stack is \n");
		while (temp->next != NULL)
		{
			printf("%d--->", temp->data);
			temp = temp->next;
		}
		printf("%d--->NULL\n\n", temp->data);
	}
}

void	set_list(t_Node *list, int new_data)
{
	struct t_Node	*new_node;
}

int	main(int argv, char **argc)
{
	int	value;

}