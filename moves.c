/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:38:10 by afanti            #+#    #+#             */
/*   Updated: 2023/02/14 13:40:40 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_top(t_data *data)
{
	if (data->map[data->player_i - 1][data->player_j] != '1'
			&& data->map[data->player_i - 1][data->player_j] != 'D')
	{
		if (data->map[data->player_i - 1][data->player_j] == 'E')
		{
			if (data->collection == 0)
				exit(1);
			else
				return ;
		}
		else
		{
			data->moves++;
			ft_putnbr_fd(data->moves);
			write (1, "\n", 1);
			if (data->map[data->player_i - 1][data->player_j] == 'C')
				data->collection--;
			ft_images("./textures/player.xpm", data, data->player_i - 1,
				data->player_j);
			ft_images("./textures/2.xpm", data, data->player_i, data->player_j);
			data->map[data->player_i - 1][data->player_j] = 'P';
			data->map[data->player_i][data->player_j] = '0';
			data->player_i--;
		}
	}
}

void	move_down(t_data *data)
{
	if (data->map[data->player_i + 1][data->player_j] != '1'
			&& data->map[data->player_i + 1][data->player_j] != 'D')
	{
		if (data->map[data->player_i + 1][data->player_j] == 'E')
		{
			if (data->collection == 0)
				exit(1);
			else
				return ;
		}
		else
		{
			data->moves++;
			ft_putnbr_fd(data->moves);
			write (1, "\n", 1);
			if (data->map[data->player_i + 1][data->player_j] == 'C')
				data->collection--;
			ft_images("./textures/player.xpm", data, data->player_i + 1,
				data->player_j);
			ft_images("./textures/2.xpm", data, data->player_i, data->player_j);
			data->map[data->player_i + 1][data->player_j] = 'P';
			data->map[data->player_i][data->player_j] = '0';
			data->player_i++;
		}
	}
}

void	move_right(t_data *data)
{
	if (data->map[data->player_i][data->player_j + 1] != '1'
			&& data->map[data->player_i][data->player_j + 1] != 'D')
	{
		if (data->map[data->player_i][data->player_j + 1] == 'E')
		{
			if (data->collection == 0)
				exit(1);
			else
				return ;
		}
		else
		{
			data->moves++;
			ft_putnbr_fd(data->moves);
			write (1, "\n", 1);
			if (data->map[data->player_i][data->player_j + 1] == 'C')
				data->collection--;
			ft_images("./textures/player.xpm", data, data->player_i,
				data->player_j + 1);
			ft_images("./textures/2.xpm", data, data->player_i, data->player_j);
			data->map[data->player_i][data->player_j + 1] = 'P';
			data->map[data->player_i][data->player_j] = '0';
			data->player_j++;
		}
	}
}

void	move_left(t_data *data)
{
	if (data->map[data->player_i][data->player_j - 1] != '1'
			&& data->map[data->player_i][data->player_j - 1] != 'D')
	{
		if (data->map[data->player_i][data->player_j - 1] == 'E')
		{
			if (data->collection == 0)
				exit(1);
			else
				return ;
		}
		else
		{
			data->moves++;
			ft_putnbr_fd(data->moves);
			write (1, "\n", 1);
			if (data->map[data->player_i][data->player_j - 1] == 'C')
				data->collection--;
			ft_images("./textures/player.xpm", data, data->player_i,
				data->player_j - 1);
			ft_images("./textures/2.xpm", data, data->player_i, data->player_j);
			data->map[data->player_i][data->player_j - 1] = 'P';
			data->map[data->player_i][data->player_j] = '0';
			data->player_j--;
		}
	}
}

int	render_next_frame(int key, t_data *data)
{
	if (key == 126 || key == 13)
		move_top(data);
	if (key == 125 || key == 1)
		move_down(data);
	if (key == 0 || key == 123)
		move_left(data);
	if (key == 124 || key == 2)
		move_right(data);
	if (data->collection == 0)
		ft_images("./textures/open_door.xpm", data, data->exit_i, data->exit_j);
	if (key == 53)
	{
		mlx_destroy_window(data->cc->mlx, data->cc->mlx_win);
		exit(1);
	}
	return (0);
}
