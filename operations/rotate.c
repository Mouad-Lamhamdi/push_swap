/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:08:48 by molamham          #+#    #+#             */
/*   Updated: 2025/02/12 20:14:46 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = lstlast(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_list **stack, bool print)
{
	rotate(stack);
	if (print)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack, bool print)
{
	rotate(stack);
	if (print)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print)
		write(1, "rr\n", 3);
}
