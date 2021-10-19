/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:40:47 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/15 18:03:21 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(char *str, t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*leaf;

	if (!*stack)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	leaf = *stack;
	while (leaf->next)
		leaf = leaf->next;
	leaf->next = tmp;
	tmp->next = NULL;
	if (ft_strncmp(str, "rr", ft_strlen(str)))
		ft_printf("%s\n", str);
	ft_pos_rec(stack);
}

void	ft_rr(char *str, t_stack **a, t_stack **b)
{
	ft_rotate(str, a);
	ft_rotate(str, b);
	ft_printf("%s\n", str);
}
