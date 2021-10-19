/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_step_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:28:53 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/17 20:28:55 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_count_step_up(t_stack **stack)
{
	t_stack	*tmp;
	int		max;
	int		mid;

	tmp = *stack;
	max = ft_lst_size(stack);
	mid = (max / 2 + 1);
	while (tmp)
	{
		if (tmp->pos < mid)
			tmp->step = tmp->pos - 1;
		else
			tmp->step = max - tmp->pos + 1;
		tmp = tmp->next;
	}
}
