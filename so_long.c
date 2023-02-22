/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:37:01 by afanti            #+#    #+#             */
/*   Updated: 2023/02/19 11:55:45 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialiser(t_data *data)
{
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->i = 0;
	data->j = 0;
	data->y = 0;
	data->f = 0;
	data->collection = 0;
	data->moves = 0;
}

void	ft_images(char *str, t_data *data, int i, int j)
{
	data->cc->img = mlx_xpm_file_to_image(data->cc->mlx, str, &data
			->cc->img_width, &data->cc->img_height);
	if (!data->cc->img)
		return ;
	mlx_put_image_to_window(data->cc->mlx, data
		->cc->mlx_win, data->cc->img, j * 50, i * 50);
}

void	firstmain(t_data *data)
{
	while (data->map[data->i])
	{
		data->j = 0;
		while (data->map[data->i][data->j])
		{
			if (data->map[data->i][data->j] == 'D')
				ft_images("./textures/5.xpm", data, data->i, data->j);
			else if (data->map[data->i][data->j] == 'E' )
				ft_images("./textures/close_door.xpm", data, data->i, data->j);
			else if (data->map[data->i][data->j] == '0')
				ft_images("./textures/2.xpm", data, data->i, data->j);
			else if (data->map[data->i][data->j] == 'P')
				ft_images("./textures/player.xpm", data, data->i, data->j);
			else if (data->map[data->i][data->j] == 'C')
				ft_images("./textures/colle1.xpm", data, data->i, data->j);
			else if (data->map[data->i][data->j] == 'Z')
				ft_images("./textures/5.xpm", data, data->i, data->j);
			else if (data->map[data->i][data->j] == '1')
				ft_images("./textures/7.xpm", data, data->i, data->j);
			data->j++;
		}
		data->i++;
	}
}

void	lastmain(t_data *data)
{
	data->mapcopy = copy_of_mapppe(data->map);
	initialiser(data);
	check_len_of_map(data);
	check_path(data->player_i, data->player_j, data);
	check_path1(data->player_i, data->player_j, data);
	check_e(data);
	for_draw(data);
	data->cc->img_height = 50;
	data->cc->img_width = 50;
	data->cc->mlx = mlx_init();
	data->cc->mlx_win = mlx_new_window(
			data->cc->mlx, data->charlen * data->cc->img_width,
			data->lennumber * data->cc->img_height, "so_long");
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = NULL;
		data = malloc(sizeof(t_data));
		if (!data)
			return (0);
		data->cc = malloc(sizeof(t_vars));
		if (!data->cc)
			return (0);
		check_av(av[1]);
		data->ptr = check_map_valid(av[1]);
		data->map = ft_split(data->ptr, '\n', ft_strlen(data->ptr));
		if (!data->map)
			exit(1);
		data->mapcopy1 = copy_of_mapppe(data->map);
		lastmain(data);
		firstmain(data);
		mlx_hook(data->cc->mlx_win, 17, 0, mouse, data);
		mlx_hook(data->cc->mlx_win, 2, 0, render_next_frame, data);
		mlx_loop(data->cc->mlx);
		mlx_destroy_window(data->cc->mlx, data->cc->mlx_win);
	}
	print_error("there is more than 2 argement");
}
