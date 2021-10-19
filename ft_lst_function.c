/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 14:38:43 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/17 19:34:15 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_lst_new(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->place = 0;
	new->pos = 0;
	new->step = 0;
	new->step_push = 0;
	new->keep = 0;
	new->index = 0;
	new->next = NULL;
	return (new);
}

static void	ft_lstadd_end(int content, t_stack **head)
{
	t_stack	*tmp;
	t_stack	*pointer;

	tmp = ft_lst_new(content);
	if (*head == NULL)
		*head = tmp;
	else
	{
		pointer = *head;
		while (pointer->next)
			pointer = pointer->next;
		pointer->next = tmp;
	}
}

void	ft_lst_add(int *arr, t_stack **a, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_lstadd_end(arr[i], a);
		i++;
	}
}
