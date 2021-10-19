/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_RotateRevers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 19:25:42 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/15 18:04:02 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_revers(char *str, t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*leaf;

	if (!*stack)
		return ;
	leaf = *stack;
	while (leaf->next->next)
		leaf = leaf->next;
	tmp = leaf->next;
	leaf->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	if (ft_strncmp(str, "rrr", ft_strlen(str)))
		ft_printf("%s\n", str);
	ft_pos_rec(stack);
}

void	ft_rrr(char *str, t_stack **a, t_stack **b)
{
	ft_rotate_revers(str, a);
	ft_rotate_revers(str, b);
	ft_printf("%s\n", str);
}
