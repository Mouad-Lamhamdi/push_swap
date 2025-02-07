#include "../push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	
	first = *stack;
	last = lstlast(*stack);

	last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	
	*stack = last;
	(*stack)->prev = NULL;
}
void	rra(t_list **stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}
void	rrb(t_list **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}
void	rrr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
