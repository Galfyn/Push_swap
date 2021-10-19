/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_LstSize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:18:18 by galfyn            #+#    #+#             */
/*   Updated: 2021/09/29 20:05:23 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(t_stack **stack)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
