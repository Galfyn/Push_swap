/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 18:37:02 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/12 19:29:48 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_swap(char *str, t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	tmp2 = (*stack)->next;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	(*stack) = tmp2;
	if (ft_strncmp(str, "ss", ft_strlen(str)))
		ft_printf("%s\n", str);
	ft_pos_rec(stack);
}

void	ft_ss(char *str, t_stack **a, t_stack **b)
{
	ft_swap(str, a);
	ft_swap(str, b);
	ft_printf("%s\n", str);
}
