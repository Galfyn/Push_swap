/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:25:08 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/09 16:16:08 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_max(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*ret;
	int		max;

	tmp = *stack;
	ret = *stack;
	max = tmp->content;
	while (tmp)
	{
		if (max < tmp->content)
			max = tmp->content;
		tmp = tmp->next;
	}
	while (ret)
	{
		if (ret->content == max)
			return (ret);
		ret = ret->next;
	}
	return (NULL);
}
