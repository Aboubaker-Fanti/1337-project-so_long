/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:38:12 by afanti            #+#    #+#             */
/*   Updated: 2023/02/19 13:05:51 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*check_map_valid(char *str)
{
	int		fd;
	char	*all_lines;
	char	*line;

	all_lines = NULL;
	fd = open(str, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		all_lines = ft_strjoin(all_lines, line);
		free(line);
	}
	if (all_lines == NULL)
		print_error("file is empty!");
	return (all_lines);
}

void	checkmap(t_data *data)
{
	while (data->map[data->y])
	{
		data->f = 0;
		while (data->map[data->y][data->f])
		{
			checkmap_if(data);
			data->f++;
		}
		data->y++;
	}
	check_player_rxit_coll(data);
}

void	checkwall(t_data *data)
{
	int	i;
	int	s;

	i = 0;
	while (data->map[i])
	{
		s = 0;
		while (data->map[0][s])
		{
			if (data->map[0][s] != '1')
				print_error("there is another character in the wall");
			s++;
		}
		s = 0;
		++i;
		while (data->map[i] && i != data->lennumber - 1)
		{
			if (data->map[i][0] != '1')
				print_error("there is another character in the wall");
			i++;
		}
		i++;
	}
	check_last_wall(data);
}

void	check_len_of_map(t_data *data)
{
	int	i;
	int	s;
	int	d;

	i = 0;
	while (data->map[i])
	{
		s = 0;
		while (data->map[i][s])
			s++;
		if (i != 0)
		{
			if (s != d)
				print_error("len of map not equal");
		}
		d = s;
		i++;
	}
	data->charlen = d;
	data->lennumber = i;
	if (data->lennumber < 2)
		print_error("check your map, there is just wall");
	checkwall(data);
}

void	check_last_wall(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i][data->charlen - 1] != '1')
			print_error("there is another character in the wall");
		i++;
	}
	i = 0;
	while (data->map[data->lennumber - 1][i])
	{
		if (data->map[data->lennumber - 1][i] != '1')
			print_error("there is another character in the wall");
		i++;
	}
	checkmap(data);
}
