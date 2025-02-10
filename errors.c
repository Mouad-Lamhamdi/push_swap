/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:08:29 by molamham          #+#    #+#             */
/*   Updated: 2025/02/10 09:41:57 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **a)
{
	t_list	*tmp;
	t_list	*current;

	if (!*a)
		return ;
	current = *a;
	while (current)
	{
		tmp = current->next;
		free(tmp);
		current = tmp;
	}
	*a = NULL;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_error(t_list **a)
{
	free_stack(a);
	write(1, "Error\n", 6);
	exit(1);
}

int	syntax_check(char *str)
{
	int	i;

	i = 0;
	if ((str[0] == '+' || str[0] == '-') && !ft_isdigit(str[1]))
		return (1);
	else if ((str[0] == '+' || str[0] == '-') && ft_isdigit(str[1]))
		i = 2;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_dup(t_list *stack, long n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->data == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}
