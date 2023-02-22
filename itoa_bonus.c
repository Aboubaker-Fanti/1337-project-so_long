/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:37:33 by afanti            #+#    #+#             */
/*   Updated: 2023/02/19 11:05:08 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_len(long i)
{
	int	k;

	k = 0;
	if (i <= 0)
	{
		k++;
		i *= -1;
	}
	while (i)
	{
		i /= 10;
		k++;
	}
	return (k);
}

char	*ft_itoa(int n)
{
	long	s;
	int		c;
	char	*str;

	s = n;
	c = ft_len(s);
	str = malloc(sizeof(char) * (c + 1));
	if (!str)
		return (NULL);
	str[c] = '\0';
	if (s == 0)
		str[0] = '0';
	if (s < 0)
	{
		str[0] = '-';
		s = s * -1;
	}
	while (s > 0)
	{
		str[--c] = 48 + (s % 10);
		s /= 10;
	}
	return (str);
}

int	mousee(t_data *data)
{
	mlx_destroy_window(data->cc->mlx, data->cc->mlx_win);
	exit(1);
}

void	fn_loopp(t_data *data, int i, int s, int v)
{
	if (v == 100 && data->map[i][s] == 'C')
		ft_images("./textures_bonus/colle1.xpm", data, i, s);
	else if (v == 1200 && data->map[i][s] == 'C')
		ft_images("./textures_bonus/colle2.xpm", data, i, s);
	else if (v == 2400 && data->map[i][s] == 'C')
		ft_images("./textures_bonus/colle3.xpm", data, i, s);
	else if (v == 3600 && data->map[i][s] == 'C')
		ft_images("./textures_bonus/colle4.xpm", data, i, s);
	else if (v == 4800 && data->map[i][s] == 'C')
		ft_images("./textures_bonus/colle5.xpm", data, i, s);
	else if (v == 6000 && data->map[i][s] == 'C')
		ft_images("./textures_bonus/colle6.xpm", data, i, s);
}

void	copy_of_mapp(char **str1, char **str, int i, int s)
{
	while (str[i][s])
	{
		str1[i][s] = str[i][s];
		s++;
	}
	str1[i][s] = 0;
}
