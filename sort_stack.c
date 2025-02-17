/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:06:57 by molamham          #+#    #+#             */
/*   Updated: 2025/02/17 14:21:44 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target)
		rr(a, b, true);
	set_index(*a);
	set_index(*b);
}

void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target)
		rrr(a, b, true);
	set_index(*a);
	set_index(*b);
}

void	push_a_to_b(t_list **a, t_list **b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->top_half && cheapest_node->target->top_half)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->top_half) && !(cheapest_node->target->top_half))
		rev_rotate_both(a, b, cheapest_node);
	move_to_top(a, cheapest_node, 'a');
	move_to_top(b, cheapest_node->target, 'b');
	pb(a, b, true);
}

void	push_b_to_a(t_list **a, t_list **b)
{
	move_to_top(a, (*b)->target, 'a');
	pa(a, b, true);
}

void	sort_stack(t_list **a, t_list **b)
{
	int	len_a;

	len_a = lstsize(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, true);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(a, b, true);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		push_a_to_b(a, b);
	}
	quick_sort(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		push_b_to_a(a, b);
	}
	set_index(*a);
	min_to_top(a);
}
