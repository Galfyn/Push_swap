/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:20:45 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/18 10:44:30 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_mass(char **mass, char *str)
{
	int	i;

	i = 0;
	while (mass[i])
	{
		free(mass[i]);
		i++;
	}
	ft_printf("%s\n", str);
	exit(1);
}

void	ft_free_arr(int *arr, char *str)
{
	free(arr);
	ft_printf("%s\n", str);
	exit(1);
}

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}
