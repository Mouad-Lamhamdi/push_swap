/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:08:44 by molamham          #+#    #+#             */
/*   Updated: 2025/02/12 20:13:21 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = lstlast(*stack);
	last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
	(*stack)->prev = NULL;
}

void	rra(t_list **stack, bool print)
{
	reverse_rotate(stack);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack, bool print)
{
	reverse_rotate(stack);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}
