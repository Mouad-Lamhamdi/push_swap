/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:06:45 by molamham          #+#    #+#             */
/*   Updated: 2025/02/10 09:20:46 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	stack_init(&a, av + 1);
	if (!stack_sorted(a))
	{
		if (lstsize(a) == 2)
			sa(&a);
		else if (lstsize(a) == 3)
			quick_sort(&a);
		else
			sort_stack(&a, &b);
	}
	print_stack(&a);
}
