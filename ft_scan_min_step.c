/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scan_min_step.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:29:47 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/17 15:52:15 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_scan_min_step_b(t_stack **b)
{
	t_stack	*tmp;
	int		index;
	int		min_step;

	tmp = *b;
	while (tmp->step_push < 0)
		tmp = tmp->next;
	min_step = tmp->step_push;
	index = tmp->index;
	while (tmp)
	{
		if (min_step > tmp->step_push && tmp->step_push > 0)
		{
			index = tmp->index;
			min_step = tmp->step_push;
		}
		tmp = tmp->next;
	}
	tmp = *b;
	while (tmp->index != index)
		tmp = tmp->next;
	return (tmp);
}

t_stack	*ft_scan_min_step_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->index != (*b)->place)
		tmp = tmp->next;
	return (tmp);
}
