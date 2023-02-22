/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:10:19 by afanti            #+#    #+#             */
/*   Updated: 2023/02/19 10:39:03 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "get_next_line/get_next_line.h"

typedef struct s_vars{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_width;
	int		img_height;
}				t_vars;

typedef struct s_data{
	int		e;
	int		c;
	int		p;
	int		i;
	int		j;
	int		y;
	int		f;
	char	**map;
	char	**mapcopy;
	char	**mapcopy1;
	int		charlen;
	int		lennumber;
	char	*ptr;
	int		player_i;
	int		moves;
	int		player_j;
	int		collection;
	int		exit_i;
	int		exit_j;
	t_vars	*cc;
}			t_data;

char	*check_map_valide(char *str);
void	check_path(int i, int j, t_data *dt);
void	check_new_line(char *s, int i);
void	check_av(char *str);
char	**ft_split(char *s, char c, int i);
void	copy_of_map(t_data *data);
void	print_error(char *str);
void	check_player_rxit_coll(t_data *data);
void	check_last_wall(t_data *data);
void	check_path1(int i, int j, t_data *dt);
void	check_e(t_data *data);
void	check_len_of_map(t_data *data);
void	for_draw(t_data *data);
void	last(t_data *data);
void	ft_images(char *str, t_data *data, int i, int j);
int		render_next_frame(int key, t_data *data);
void	checkmap_if(t_data *data);
int		fn_loop(t_data *data);
char	*ft_itoa(int n);
void	fn_loopp(t_data *data, int i, int s, int v);
int		fire_loop(t_data *data);
void	fire_loopp(t_data *data, int i, int s, int v);
void	copy_of_mapp(char **str1, char **str, int i, int s);
char	**copy_of_mape(char **str);
int		mousee(t_data *data);

#endif
