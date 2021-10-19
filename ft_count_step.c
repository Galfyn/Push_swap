/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_step.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:55:13 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/17 20:26:50 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_one_place(t_stack **a, t_stack **b_elem, int min, int max)
{
	int		last;
	t_stack	*tmp;

	tmp = *a;
	last = ft_find_last_elem(a)->index;
	if (last < (*b_elem)->index && (*a)->index > (*b_elem)->index)
	{
		(*b_elem)->step_push = (*a)->step + (*b_elem)->step + 1;
		(*b_elem)->place = (*a)->index;
	}
	while (tmp)
	{
		if ((*b_elem)->index < min || (*b_elem)->index > max)
		{
			if (tmp->index == min)
			{
				(*b_elem)->step_push = tmp->step + (*b_elem)->step + 1;
				(*b_elem)->place = tmp->index;
				break ;
			}
		}
		tmp = tmp->next;
	}
}

static void	ft_two_place(t_stack **a, t_stack **b_elem)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if ((*b_elem)->index > tmp->index)
			break ;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->index > (*b_elem)->index)
		{
			(*b_elem)->step_push = tmp->step + (*b_elem)->step + 1;
			(*b_elem)->place = tmp->index;
			break ;
		}
		tmp = tmp->next;
	}
}

static void	ft_three_place(t_stack **a, t_stack **b_elem)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->index > (*b_elem)->index)
		{
			(*b_elem)->step_push = tmp->step + (*b_elem)->step + 1;
			(*b_elem)->place = tmp->index;
			break ;
		}
		tmp = tmp->next;
	}
}

static void	ft_scan_place(t_stack **a, t_stack **b_elem)
{
	int		min;
	int		max;
	int		last;

	min = ft_find_min(a)->index;
	max = ft_find_max(a)->index;
	last = ft_find_last_elem(a)->index;
	if ((*b_elem)->index < min || (*b_elem)->index > max
		|| ((*a)->index > (*b_elem)->index && last < (*b_elem)->index))
		ft_one_place(a, b_elem, min, max);
	else if ((*b_elem)->index < (*a)->index)
		ft_two_place(a, b_elem);
	else
		ft_three_place(a, b_elem);
}

void	ft_count_step(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	ft_count_step_up(a);
	ft_count_step_up(b);
	tmp = *b;
	while (tmp)
	{
		tmp->step_push = -1;
		ft_scan_place(a, &tmp);
		tmp = tmp->next;
	}
}
