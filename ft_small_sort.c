/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 15:14:44 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/17 20:33:38 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_small_sort(t_stack **a)
{
	while (!ft_check_sort(a))
	{
		if ((*a)->index > (*a)->next->index)
			ft_swap("sa", a);
		if (ft_lst_size(a) == 3)
			if ((*a)->next->index > (*a)->next->next->index)
				ft_rotate_revers("rra", a);
	}
}

static void	ft_push_b(t_stack **a, t_stack **b)
{
	while (ft_check_markup(a))
	{
		if ((*a)->keep == 1)
			ft_rotate("ra", a);
		else
			ft_push("pb", a, b);
	}
}

void	ft_small_sort5(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		min;

	min = ft_find_min(a)->index;
	tmp = *a;
	while (tmp)
	{
		tmp->keep = 1;
		if (tmp->index == min || tmp->index == min + 1)
			tmp->keep = 0;
		tmp = tmp->next;
	}
	ft_push_b(a, b);
	ft_small_sort(a);
	if (ft_lst_size(b) == 2)
	{
		if ((*b)->index < (*b)->next->index)
			ft_rotate("rb", b);
		ft_push("pa", b, a);
		ft_push("pa", b, a);
	}
	else
		ft_push("pa", b, a);
}
