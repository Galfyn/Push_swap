/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_CheckSort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:48:07 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/01 19:30:57 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	tmp = *stack;
	while (tmp->next)
	{
		tmp_next = tmp->next;
		while (tmp_next)
		{
			if (tmp->content > tmp_next->content)
				return (0);
			tmp_next = tmp_next->next;
		}
		tmp = tmp->next;
	}
	return (1);
}
