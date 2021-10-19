/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:03:31 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/09 16:16:08 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_min( t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*ret;
	int		min;

	tmp = *stack;
	ret = *stack;
	min = tmp->content;
	while (tmp)
	{
		if (min >= tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	while (ret)
	{
		if (ret->content == min)
			return (ret);
		ret = ret->next;
	}
	return (NULL);
}
