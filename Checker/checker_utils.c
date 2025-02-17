/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:42:38 by molamham          #+#    #+#             */
/*   Updated: 2025/02/17 16:12:31 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

bool	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (false);
		i++;
	}
	return (true);
}

void	check_falied(t_list **a, t_list **b, char *commad)
{
	free_stack(a);
	free_stack(b);
	free(commad);
	get_next_line(-1);
	write(2, "Error\n", 6);
	exit (1);
}

void	check(t_list **a, t_list **b, char *command)
{
	if (ft_strcmp("sa\n", command))
		sa(a, false);
	else if (ft_strcmp("sb\n", command))
		sb(b, false);
	else if (ft_strcmp("ss\n", command))
		ss(a, b, false);
	else if (ft_strcmp("pa\n", command))
		pa(a, b, false);
	else if (ft_strcmp("pb\n", command))
		pb(a, b, false);
	else if (ft_strcmp("ra\n", command))
		ra(a, false);
	else if (ft_strcmp("rb\n", command))
		rb(b, false);
	else if (ft_strcmp("rr\n", command))
		rr(a, b, false);
	else if (ft_strcmp("rra\n", command))
		rra(a, false);
	else if (ft_strcmp("rrb\n", command))
		rrb(b, false);
	else if (ft_strcmp("rrr\n", command))
		rrr(a, b, false);
	else
		check_falied(a, b, command);
}

void	apply(t_list **a, t_list **b)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		check(a, b, command);
		free(command);
		command = get_next_line(0);
	}
	free(command);
	get_next_line(-1);
	if (*b || !(stack_sorted(*a)))
	{
		free_stack(a);
		free_stack(b);
		write(1, "KO\n", 3);
	}
	else if (stack_sorted(*a) && !*b)
	{
		free_stack(a);
		free_stack(b);
		write(1, "OK\n", 3);
	}
}
