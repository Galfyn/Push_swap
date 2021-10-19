/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:27:07 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/17 19:48:13 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(char *str, t_stack **pull, t_stack **push)
{
	t_stack	*tmp;

	if (!*pull)
		return ;
	tmp = (*pull)->next;
	(*pull)->next = *push;
	*push = *pull;
	*pull = tmp;
	ft_printf("%s\n", str);
	ft_pos_rec(pull);
	ft_pos_rec(push);
}
