/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:07:18 by molamham          #+#    #+#             */
/*   Updated: 2025/02/10 09:19:05 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_smallest(t_list *stack)
{
	t_list	*smallest;

	if (!stack)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (stack->data < smallest->data)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

static	void	set_target_b(t_list *a, t_list *b)
{
	t_list	*tmp;
	t_list	*target;
	long	flag;

	while (b)
	{
		tmp = a;
		flag = LONG_MAX;
		while (tmp)
		{
			if (tmp->data > b->data && tmp->data < flag)
			{
				flag = tmp->data;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (flag == LONG_MAX)
			b->target = get_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_nodes_b(t_list *a, t_list *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}
