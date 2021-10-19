/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galfyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 01:46:39 by galfyn            #+#    #+#             */
/*   Updated: 2021/10/18 10:17:10 by galfyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_digit(char **ar)
{
	int	i;
	int	j;

	i = 0;
	while (ar[i])
	{
		j = 0;
		while (ar[i][j])
		{
			if (ar[i][j] == '-' || ar[i][j] == '+')
				j++;
			if (ft_isdigit(ar[i][j]))
			{
				j++;
				if (!ft_isdigit(ar[i][j]) && ar[i][j] != '\0')
					ft_free_mass(ar, "Arguments specified incorrectly");
			}
			else
				ft_free_mass(ar, "Arguments specified incorrectly");
		}
		i++;
	}
}

static int	ft_count_number(char **ar)
{
	int		count;
	int		i;
	int		j;
	char	**tmp;

	count = 0;
	i = 1;
	while (ar[i])
	{
		tmp = ft_split(ar[i], ' ');
		ft_check_digit(tmp);
		j = 0;
		while (tmp[j])
		{
			free(tmp[j]);
			count++;
			j++;
		}
		free(tmp);
		i++;
	}
	return (count);
}

static long	ft_atoi_ps(const char *str)
{
	int		negative;
	long	result;
	int		i;

	negative = 1;
	result = 0;
	i = 0;
	while (str[i] && ft_isspace(str[i]) == 1)
		++i;
	if (str[i] == '-')
		negative = -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		++i;
	}
	return (result * negative);
}

static void	ft_add_arr(char **argv, int *arr)
{
	int		i;
	int		j;
	int		k;
	long	nb;
	char	**tmp;

	i = 1;
	k = 0;
	while (argv[i])
	{
		j = 0;
		tmp = ft_split(argv[i], 32);
		while (tmp[j])
		{
			nb = ft_atoi_ps(tmp[j]);
			if (nb < -2147483648 || nb > 2147483647)
				ft_free_arr(arr, "Integer overflow\n");
			arr[k] = (int)nb;
			free(tmp[j]);
			k++;
			j++;
		}
		i++;
		free(tmp);
	}
}

void	ft_handler(char **argv, t_stack **a)
{
	int	count;
	int	*arr;

	count = ft_count_number(argv);
	arr = (int *) malloc(sizeof(int) * count);
	if (!arr)
		error("Failed to allocate memory");
	ft_add_arr(argv, arr);
	ft_check_dup(arr, count);
	ft_lst_add(arr, a, count);
	free(arr);
	ft_index(a);
	ft_pos_rec(a);
}
