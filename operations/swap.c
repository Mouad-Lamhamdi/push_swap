/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:08:52 by molamham          #+#    #+#             */
/*   Updated: 2025/02/12 20:15:33 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
	*stack = second;
}

void	sa(t_list **stack, bool print)
{
	swap(stack);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack, bool print)
{
	swap(stack);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, bool print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}
