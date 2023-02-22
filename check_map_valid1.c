/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:38:14 by afanti            #+#    #+#             */
/*   Updated: 2023/02/14 13:52:08 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player_error(t_data *data)
{
	if (data->e != 1)
		print_error("check exit");
	else if (data->c <= 0)
		print_error("there is nothing to eat");
	else if (data->p != 1)
		print_error("check player");
}

void	check_player_rxit_coll(t_data *data)
{
	int	i;
	int	a;

	i = 0;
	while (data->map[i])
	{
		a = 0;
		while (data->map[i][a])
		{
			if (data->map[i][a] == 'C')
				data->c++;
			else if (data->map[i][a] == 'E')
				data->e++;
			else if (data->map[i][a] == 'P')
				data->p++;
			a++;
		}
		i++;
	}
	check_player_error(data);
}

void	print_error(char *str)
{
	int	i;

	i = 0;
	write (2, "Error\n", 6);
	while (str[i])
	{
		write (2, &str[i], 1);
		i++;
	}
	exit (1);
}

void	check_new_line(char *s, int i)
{
	if (s[0] == '\n')
		print_error("New Line fl bdya");
	else if (s[i - 1] == '\n')
		print_error("New Line flekher");
	i = 1;
	while (s[i])
	{
		if (s[i] == '\n')
			if (s[i + 1] == '\n')
				print_error("New Line Lwest");
		i++;
	}
}

void	copy_of_mappe(char **str1, char **str, int i, int s)
{
	while (str[i][s])
	{
		str1[i][s] = str[i][s];
		s++;
	}
	str1[i][s] = 0;
}
