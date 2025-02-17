/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:07:25 by molamham          #+#    #+#             */
/*   Updated: 2025/02/14 09:40:12 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list *stack)
{
	int	i;
	int	mid;

	i = 0;
	if (!stack)
		return ;
	mid = lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= mid)
			stack->top_half = true;
		else
			stack->top_half = false;
		stack = stack->next;
		++i;
	}
}

static void	set_target_a(t_list *a, t_list *b)
{
	t_list	*tmp;
	t_list	*target;
	long	flag;

	while (a)
	{
		tmp = b;
		flag = LONG_MIN;
		while (tmp)
		{
			if (tmp->data < a->data && tmp->data > flag)
			{
				flag = tmp->data;
				target = tmp;
			}
			tmp = tmp->next;
		}
		if (flag == LONG_MIN)
			a->target = get_biggest(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	push_cost_a(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = lstsize(a);
	len_b = lstsize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->top_half))
			a->push_cost = len_a - (a->index);
		if (a->target->top_half)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}

void	set_cheapest(t_list *stack)
{
	long	cheapest_value;
	t_list	*cheapest_node;
	t_list	*tmp;

	if (!stack)
		return ;
	tmp = stack;
	while (tmp)
	{
		tmp->cheapest = false;
		tmp = tmp->next;
	}
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_list *a, t_list *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	push_cost_a(a, b);
	set_cheapest(a);
}
