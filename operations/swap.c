#include "../push_swap.h"

void	swap(t_list **stack)
{
	t_list *first;
	t_list *second;

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

void	sa(t_list **stack)
{
	swap(stack);
	ft_printf("sa\n");
}
void	sb(t_list **stack)
{
	swap(stack);
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}