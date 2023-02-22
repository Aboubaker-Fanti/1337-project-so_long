/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:00:23 by afanti            #+#    #+#             */
/*   Updated: 2023/02/19 10:39:58 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**copy_of_mape(char **str)
{
	int		i;
	int		s;
	int		s1;
	char	**str1;

	i = 0;
	s1 = 0;
	while (str[i])
		i++;
	while (str[0][s1])
		s1++;
	str1 = malloc((i + 1) * sizeof(char *));
	i = 0;
	while (str[i])
	{
		s = 0;
		str1[i] = malloc(s1 * sizeof(char) + 1);
		copy_of_mapp(str1, str, i, s);
		i++;
	}
	str1[i] = NULL;
	return (str1);
}

void	check_path(int i, int j, t_data *dt)
{
	if (i < 0 || j < 0 || i >= dt->lennumber
		|| j >= dt->charlen || dt->mapcopy[i][j] == '1'
		|| dt->mapcopy[i][j] == 'N')
		return ;
	dt->mapcopy[i][j] = '1';
	check_path(i + 1, j, dt);
	check_path(i - 1, j, dt);
	check_path(i, j + 1, dt);
	check_path(i, j - 1, dt);
}

void	check_p_c(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	while (data->mapcopy1[i])
	{
		y = 0;
		while (data->mapcopy1[i][y])
		{
			if (data->mapcopy1[i][y] == 'C')
				print_error("player can't eat c");
			if (data->mapcopy1[i][y] == 'P')
				print_error("player can't move");
			y++;
		}
		i++;
	}
}

void	check_path1(int i, int j, t_data *dt)
{
	if (i < 0 || j < 0 || i >= dt->lennumber || j >= dt->charlen
		|| dt->mapcopy1[i][j] == '1' || dt->mapcopy1[i][j] == 'E'
		|| dt->mapcopy1[i][j] == 'N')
		return ;
	dt->mapcopy1[i][j] = '1';
	check_path1(i + 1, j, dt);
	check_path1(i - 1, j, dt);
	check_path1(i, j + 1, dt);
	check_path1(i, j - 1, dt);
}

void	check_e(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	while (data->mapcopy[i])
	{
		y = 0;
		while (data->mapcopy[i][y])
		{
			if (data->mapcopy[i][y] == 'E')
				print_error("player can't exit");
			y++;
		}
		i++;
	}
	check_p_c(data);
}
