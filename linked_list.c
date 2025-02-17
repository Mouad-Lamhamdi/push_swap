/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:07:41 by molamham          #+#    #+#             */
/*   Updated: 2025/02/11 10:43:34 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstnew(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_list	*lstlast(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstaddback(t_list **head, t_list *node)
{
	t_list	*last;

	if (!head || !node)
		return ;
	if (!*head)
	{
		node->prev = NULL;
		node->next = NULL;
		*head = node;
	}
	else
	{
		last = lstlast(*head);
		last->next = node;
		node->prev = last;
		node->next = NULL;
	}
}

int	lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
