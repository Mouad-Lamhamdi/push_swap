/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:08:37 by molamham          #+#    #+#             */
/*   Updated: 2025/02/12 20:11:59 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **dest, t_list **src)
{
	t_list	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		node_to_push->next->prev = node_to_push;
		*dest = node_to_push;
	}
}

void	pa(t_list **a, t_list **b, bool print)
{
	push(a, b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, bool print)
{
	push(b, a);
	if (print)
		write(1, "pb\n", 3);
}
