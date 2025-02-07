#include "../push_swap.c"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = lstlast(*stack);

	*stack = first->next;
	(*stack)->prev = NULL;

	last->next = first;
	first->prev = last;
	first->next = NULL;
}
void	ra(t_list **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}
void	rb(t_list **stack)
{
	rotate(stack);
	ft_printf("rb\n");
}
void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}