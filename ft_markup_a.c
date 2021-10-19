/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_markup_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:58:50 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/19 16:48:35 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_chain(t_stack **head, t_stack **markup_a, int nb)
{
	int		compare;
	int		max_chain;
	t_stack	*tmp;

	tmp = *markup_a;
	compare = nb;
	max_chain = 1;
	tmp->keep = 1;
	tmp = tmp->next;
	while (tmp)
	{
		tmp->keep = 0;
		if (compare < tmp->index)
		{
			max_chain++;
			compare = tmp->index;
			tmp->keep = 1;
		}
		tmp = tmp->next;
		if (tmp == NULL)
			tmp = *head;
		if (tmp->index == nb)
			break ;
	}
	return (max_chain);
}

static void	ft_markup_two(t_stack **a)
{
	int		mid_index;
	t_stack	*tmp;

	mid_index = ft_find_max(a)->index / 2;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index < mid_index && tmp->keep != 1)
			tmp->keep = 2;
		tmp = tmp->next;
	}
}

void	ft_markup_a(t_stack **a)
{
	int		max_chain;
	int		index;
	t_stack	*tmp;

	tmp = *a;
	max_chain = 0;
	while (tmp)
	{
		if (max_chain < ft_max_chain(a, &tmp, tmp->index))
		{
			max_chain = ft_max_chain(a, &tmp, tmp->index);
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp->index != index)
		tmp = tmp->next;
	ft_max_chain(a, &tmp, tmp->index);
	ft_markup_two(a);
}
