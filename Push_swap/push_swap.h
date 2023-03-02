/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrechin <kbrechin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:16:15 by kbrechin          #+#    #+#             */
/*   Updated: 2023/03/02 16:49:29 by kbrechin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack_a
{
	int				num;
	struct s_stack_a	*next_node;
	struct s_stack_a	*prev_node;
}	t_stack_a;

typedef struct s_stack_b
{
	int				num;
	struct s_stack_b	*next_node;
	struct s_stack_b	*prev_node;
}	t_stack_b;

typedef struct s_stacks
{
	t_stack_a	a;
	t_stack_b	b;
}	t_stacks;