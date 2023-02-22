/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:45:01 by afanti            #+#    #+#             */
/*   Updated: 2023/02/14 08:42:12 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	for_draw(t_data *data)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (data->map[d])
	{
		while (data->map[0][i])
		{
			if (data->map[0][i] == '1')
				data->map[0][i] = 'D';
			i++;
		}
		i = 0;
		++d;
		while (data->map[d][0] && d != data->lennumber - 1)
		{
			if (data->map[d][0] == '1')
				data->map[d][0] = 'D';
			d++;
		}
		d++;
	}
	last(data);
}

void	last(t_data *data)
{
	int	i;
	int	s;

	i = 1;
	s = 0;
	while (data->map[i])
	{
		while (data->map[i][data->charlen - 1] && i != data->lennumber - 1)
		{
			if (data->map[i][data->charlen - 1] == '1')
				data->map[i][data->charlen - 1] = 'D';
			i++;
		}
		i++;
	}
	i = 0;
	s = data->lennumber - 1;
	while (data->map[s][i])
	{
		if (data->map[s][i] == '1')
			data->map[s][i] = 'D';
		i++;
	}
}

void	middleofmap(t_data *data)
{
	int	i;
	int	d;

	i = 2;
	d = 2;
	while (data->map[i][d])
	{
		if (d != 10 && d != 20 && d != data->charlen - 2
			&& data->map[i][d] != 'Z' && d != data->charlen - 1)
			data->map[i][d] = 'Z';
		d++;
	}
}

void	checkmap_if(t_data *data)
{
	if (data->map[data->y][data->f] != 'E' && data
		->map[data->y][data->f] != 'C' && data
		->map[data->y][data->f] != '1' && data
		->map[data->y][data->f] != '0'
		&& data->map[data->y][data->f] != 'P')
		print_error("there is new character in the map");
	if (data->map[data->y][data->f] == 'P')
	{
		data->player_i = data->y;
		data->player_j = data->f;
	}
	if (data->map[data->y][data->f] == 'C')
		data->collection++;
	if (data->map[data->y][data->f] == 'E')
	{
		data->exit_i = data->y;
		data->exit_j = data->f;
	}
}

int	mouse(t_data *data)
{
	mlx_destroy_window(data->cc->mlx, data->cc->mlx_win);
	exit(1);
}
