/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:46:18 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/19 15:20:01 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **a)
{
	t_stack	*del;
	t_stack	*current;
	int		lst_size;
	int		i;

	i = 0;
	lst_size = ft_lst_size(a);
	current = *a;
	while (i < lst_size)
	{
		del = current;
		current = current->next;
		free(del);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (!argv[1][0])
		error("Arguments specified incorrectly");
	if (argc < 2)
		error("Invalid number of arguments");
	ft_handler(argv, &a);
	if (ft_check_sort(&a))
	{
		ft_free_stack(&a);
		exit(0);
	}
	if (ft_lst_size(&a) <= 3)
		ft_small_sort(&a);
	if (ft_lst_size(&a) == 4 || ft_lst_size(&a) == 5)
		ft_small_sort5(&a, &b);
	if (ft_lst_size(&a) > 5)
		ft_middle_sort(&a, &b);
	ft_free_stack(&a);
}
