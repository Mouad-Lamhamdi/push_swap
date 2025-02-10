/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:07:32 by molamham          #+#    #+#             */
/*   Updated: 2025/02/10 09:19:30 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_biggest(t_list *stack)
{
	t_list	*biggest;

	if (!stack)
		return (NULL);
	biggest = stack;
	while (stack)
	{
		if (stack->data > biggest->data)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

void	quick_sort(t_list **stack)
{
	t_list	*biggest;

	biggest = get_biggest(*stack);
	if (*stack == biggest)
		ra(stack);
	else if ((*stack)->next == biggest)
		rra(stack);
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}
