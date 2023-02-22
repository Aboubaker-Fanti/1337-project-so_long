/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fire_test_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:08:51 by afanti            #+#    #+#             */
/*   Updated: 2023/02/19 11:04:48 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fire_loopp(t_data *data, int i, int s, int v)
{
	if (v == 100 && data->map[i][s] == 'N')
		ft_images("./textures_bonus/fire1.xpm", data, i, s);
	else if (v == 1200 && data->map[i][s] == 'N')
		ft_images("./textures_bonus/fire2.xpm", data, i, s);
	else if (v == 2400 && data->map[i][s] == 'N')
		ft_images("./textures_bonus/fire3.xpm", data, i, s);
	else if (v == 3600 && data->map[i][s] == 'N')
		ft_images("./textures_bonus/fire4.xpm", data, i, s);
	else if (v == 4800 && data->map[i][s] == 'N')
		ft_images("./textures_bonus/fire5.xpm", data, i, s);
}
