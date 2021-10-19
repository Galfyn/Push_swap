/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:14:28 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/19 16:31:40 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_to_b(t_stack **a, t_stack **b)
{
	while (ft_check_markup(a))
	{
		if ((*a)->keep == 0)
			ft_push("pb", a, b);
		else
			ft_rotate("ra", a);
	}
	while (ft_check_markup_2(a))
	{
		if ((*a)->keep == 2)
			ft_push("pb", a, b);
		else
			ft_rotate("ra", a);
	}
}

static void	ft_push_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		ft_count_step(a, b);
		while ((*b)->index != ft_scan_min_step_b(b)->index)
		{
			if (ft_scan_min_step_b(b)->pos < ft_lst_size(b) / 2 + 1)
				ft_rotate("rb", b);
			else
				ft_rotate_revers("rrb", b);
		}
		while ((*a)->index != (*b)->place)
		{
			if (ft_scan_min_step_a(a, b)->pos < ft_lst_size(a) / 2 + 1)
				ft_rotate("ra", a);
			else
				ft_rotate_revers("rra", a);
		}
		ft_push("pa", b, a);
	}
}

static void	ft_final_rotate(t_stack **a)
{
	int	min_index;
	int	min_pos;

	min_index = ft_find_min(a)->index;
	min_pos = ft_find_min(a)->pos;
	while ((*a)->index != min_index)
	{
		if (min_pos < ft_lst_size(a) / 2 + 1)
			ft_rotate("ra", a);
		else
			ft_rotate_revers("rra", a);
	}
}

void	ft_middle_sort(t_stack **a, t_stack **b)
{
	ft_markup_a(a);
	ft_count_step_up(a);
	ft_push_to_b(a, b);
	ft_push_to_a(a, b);
	ft_final_rotate(a);
}
