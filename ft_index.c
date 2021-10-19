/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:20:36 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/15 14:52:45 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_index_init(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
}

static int	ft_check_flag(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == -1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static int	ft_search_min(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == -1)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

static void	ft_add_index(t_stack **stack, int index)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack;
	min = ft_search_min(stack);
	while (tmp)
	{
		if (min > tmp->content && tmp->index == -1)
			min = tmp->content;
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp->content != min)
		tmp = tmp->next;
	tmp->index = index;
}

void	ft_index(t_stack **stack)
{
	int	index;

	index = 1;
	ft_index_init(stack);
	while (ft_check_flag(stack))
	{
		ft_add_index(stack, index);
		index++;
	}
}
