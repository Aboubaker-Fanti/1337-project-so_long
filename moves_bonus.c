/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:38:10 by afanti            #+#    #+#             */
/*   Updated: 2023/02/19 11:11:13 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_top(t_data *data)
{
	if (data->map[data->player_i - 1][data->player_j] == 'E')
	{
		if (data->collection == 0)
			exit(1);
		else
			return ;
	}
	if (data->map[data->player_i - 1][data->player_j] != '1'
			&& data->map[data->player_i - 1][data->player_j] != 'D'
			&& data->map[data->player_i - 1][data->player_j] != 'E')
	{
		data->moves++;
		if (data->map[data->player_i - 1][data->player_j] == 'N')
			exit(1);
		if (data->map[data->player_i - 1][data->player_j] == 'C')
			data->collection--;
		ft_images("./textures_bonus/player.xpm", data, data->player_i - 1,
			data->player_j);
		ft_images("./textures_bonus/2.xpm", data, data->player_i,
			data->player_j);
		data->map[data->player_i - 1][data->player_j] = 'P';
		data->map[data->player_i][data->player_j] = '0';
		data->player_i--;
	}
}

void	move_down(t_data *data)
{
	if (data->map[data->player_i + 1][data->player_j] == 'E')
	{
		if (data->collection == 0)
			exit(1);
		else
			return ;
	}
	if (data->map[data->player_i + 1][data->player_j] != '1'
			&& data->map[data->player_i + 1][data->player_j] != 'D'
			&& data->map[data->player_i + 1][data->player_j] != 'E')
	{
		data->moves++;
		if (data->map[data->player_i + 1][data->player_j] == 'N')
			exit(1);
		if (data->map[data->player_i + 1][data->player_j] == 'C')
			data->collection--;
		ft_images("./textures_bonus/player.xpm", data, data->player_i + 1,
			data->player_j);
		ft_images("./textures_bonus/2.xpm", data, data->player_i,
			data->player_j);
		data->map[data->player_i + 1][data->player_j] = 'P';
		data->map[data->player_i][data->player_j] = '0';
		data->player_i++;
	}
}

void	move_right(t_data *data)
{
	if (data->map[data->player_i][data->player_j + 1] == 'E')
	{
		if (data->collection == 0)
			exit(1);
		else
			return ;
	}
	if (data->map[data->player_i][data->player_j + 1] != '1'
			&& data->map[data->player_i][data->player_j + 1] != 'D'
			&& data->map[data->player_i][data->player_j + 1] != 'E')
	{
		data->moves++;
		if (data->map[data->player_i][data->player_j + 1] == 'N')
			exit(1);
		if (data->map[data->player_i][data->player_j + 1] == 'C')
			data->collection--;
		ft_images("./textures_bonus/player.xpm", data, data->player_i,
			data->player_j + 1);
		ft_images("./textures_bonus/2.xpm", data, data->player_i,
			data->player_j);
		data->map[data->player_i][data->player_j + 1] = 'P';
		data->map[data->player_i][data->player_j] = '0';
		data->player_j++;
	}
}

void	move_left(t_data *data)
{
	if (data->map[data->player_i][data->player_j - 1] == 'E')
	{
		if (data->collection == 0)
			exit(0);
		else
			return ;
	}
	if (data->map[data->player_i][data->player_j - 1] != '1'
			&& data->map[data->player_i][data->player_j - 1] != 'D'
			&& data->map[data->player_i][data->player_j - 1] != 'E')
	{
		data->moves++;
		if (data->map[data->player_i][data->player_j - 1] == 'N')
			exit(1);
		if (data->map[data->player_i][data->player_j - 1] == 'C')
			data->collection--;
		ft_images("./textures_bonus/player.xpm", data, data->player_i,
			data->player_j - 1);
		ft_images("./textures_bonus/2.xpm", data, data->player_i,
			data->player_j);
		data->map[data->player_i][data->player_j - 1] = 'P';
		data->map[data->player_i][data->player_j] = '0';
		data->player_j--;
	}
}

int	render_next_frame(int key, t_data *data)
{
	char	*frere;

	if (key == 126 || key == 13)
		move_top(data);
	if (key == 125 || key == 1)
		move_down(data);
	if (key == 0 || key == 123)
		move_left(data);
	if (key == 124 || key == 2)
		move_right(data);
	if (key == 53)
	{
		mlx_destroy_window(data->cc->mlx, data->cc->mlx_win);
		exit(1);
	}
	if (data->collection == 0)
		ft_images("./textures_bonus/open_door.xpm", data, data->exit_i,
			data->exit_j);
	ft_images("./textures_bonus/5.xpm", data, 0, 0);
	ft_images("./textures_bonus/5.xpm", data, 50, 0);
	frere = ft_itoa(data->moves);
	mlx_string_put(data->cc->mlx, data->cc->mlx_win, 10, 10, 0x00FF0000, frere);
	free(frere);
	return (0);
}
