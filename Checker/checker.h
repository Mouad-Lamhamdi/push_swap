/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamham <molamham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 09:40:43 by molamham          #+#    #+#             */
/*   Updated: 2025/02/14 09:40:57 by molamham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../push_swap.h"

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void	*dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	apply(t_list **a, t_list **b);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif