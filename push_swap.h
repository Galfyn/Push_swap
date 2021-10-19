/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:46:28 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/18 10:26:03 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	int				pos;
	int				place;
	int				step;
	int				keep;
	int				step_push;
	struct s_stack	*next;
}	t_stack;

void	ft_handler(char **argv, t_stack **a);
int		ft_check_sort(t_stack **stack);
void	ft_check_dup(int *arr, int count);
void	ft_pos_rec(t_stack **stack);
void	ft_index(t_stack **a);
void	error(char *str);

void	ft_lst_add(int *arr, t_stack **a, int count);
int		ft_lst_size(t_stack **stack);
void	ft_count_step_up(t_stack **stack);

void	ft_markup_a(t_stack **a);
int		ft_check_markup(t_stack **a);
int		ft_check_markup_2(t_stack **a);

void	ft_free_stack(t_stack **a);
void	ft_free_arr(int *arr, char *str);
void	ft_free_mass(char **mass, char *str);

t_stack	*ft_find_min( t_stack **stack);
t_stack	*ft_find_max(t_stack **stack);
t_stack	*ft_find_last_elem(t_stack **stack);

t_stack	*ft_scan_min_step_b(t_stack **b);
t_stack	*ft_scan_min_step_a(t_stack **a, t_stack **b);
void	ft_count_step(t_stack **a, t_stack **b);

void	ft_small_sort(t_stack **a);
void	ft_middle_sort(t_stack **a, t_stack **b);
void	ft_small_sort5(t_stack **a, t_stack **b);

void	ft_push(char *str, t_stack **pull, t_stack **push);
void	ft_rotate_revers(char *str, t_stack **stack);
void	ft_rrr(char *str, t_stack **a, t_stack **b);
void	ft_ss(char *str, t_stack **a, t_stack **b);
void	ft_rr(char *str, t_stack **a, t_stack **b);
void	ft_rotate(char *str, t_stack **stack);
void	ft_swap(char *str, t_stack **stack);

#endif
