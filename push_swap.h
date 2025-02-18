/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 09:07:57 by molamham          #+#    #+#             */
/*   Updated: 2025/02/18 14:33:12 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_list
{
	int				data;
	int				index;
	int				push_cost;
	bool			cheapest;
	bool			top_half;
	struct s_list	*target;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

// errors
int		stack_sorted(t_list *stack);
int		syntax_check(char *str);
int		check_dup(t_list *stack, long n);
void	free_stack(t_list **a);
void	ft_error(t_list **a);
void	ft_free(char **arr);

// linked list functions
t_list	*lstnew(int data);
t_list	*lstlast(t_list *lst);
void	lstaddback(t_list **head, t_list *node);
int		lstsize(t_list *lst);

// stack initialization
void	stack_init(t_list **stack, char **av, int ac);
char	**ft_split(char const *s, char c);
long	ft_atoi(char *str);
void	init_nodes_a(t_list *a, t_list *b);
void	init_nodes_b(t_list *a, t_list *b);
int		count_words(const char *s, char c);

// stack operations
void	sa(t_list **stack, bool print);
void	sb(t_list **stack, bool print);
void	ss(t_list **a, t_list **b, bool print);

void	ra(t_list **stack, bool print);
void	rb(t_list **stack, bool print);
void	rr(t_list **a, t_list **b, bool print);

void	rra(t_list **stack, bool print);
void	rrb(t_list **stack, bool print);
void	rrr(t_list **a, t_list **b, bool print);

void	pa(t_list **a, t_list **b, bool print);
void	pb(t_list **a, t_list **b, bool print);

// stack sorting
void	quick_sort(t_list **stack);
t_list	*get_cheapest(t_list *a);
void	set_index(t_list *stack);
void	move_to_top(t_list **stack, t_list *top_node, char stack_name);
t_list	*get_smallest(t_list *stack);
void	min_to_top(t_list **stack);
void	sort_stack(t_list **a, t_list **b);
void	init_nodes_a(t_list *a, t_list *b);
void	init_nodes_b(t_list *a, t_list *b);
void	push_a_to_b(t_list **a, t_list **b);
void	push_b_to_a(t_list **a, t_list **b);
t_list	*get_biggest(t_list *stack);

#endif