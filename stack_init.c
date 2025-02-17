/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:07:48 by molamham          #+#    #+#             */
/*   Updated: 2025/02/17 16:33:12 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	ft_handl_err(int ac, char **av, t_list **stack)
{
	if (ac == 2)
		ft_free(av);
	ft_error(stack);
}

void	stack_init(t_list **stack, char **av, int ac)
{
	t_list	*node;
	int		i;
	long	n;

	i = 0;
	node = *stack;
	while (av[i])
	{
		if (syntax_check(av[i]))
			ft_handl_err(ac, av, stack);
		n = ft_atoi(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			ft_handl_err(ac, av, stack);
		if (check_dup(*stack, n))
			ft_handl_err(ac, av, stack);
		node = lstnew(n);
		lstaddback(stack, node);
		i++;
	}
}
