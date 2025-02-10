/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:07:05 by molamham          #+#    #+#             */
/*   Updated: 2025/02/10 09:07:08 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_cheapest(t_list *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->cheapest == true)
			return (a);
		a = a->next;
	}
	return (NULL);
}

void	move_to_top(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->top_half)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->top_half)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	min_to_top(t_list **stack)
{
	while ((*stack)->data != get_smallest(*stack)->data)
	{
		if (get_smallest(*stack)->top_half)
			ra(stack);
		else
			rra(stack);
	}
}
