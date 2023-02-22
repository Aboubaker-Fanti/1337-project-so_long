/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:35:57 by afanti            #+#    #+#             */
/*   Updated: 2023/02/19 10:39:36 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	if (s == NULL)
	{
		write (2, "Error map is empty", 18);
		exit(1);
	}
	if (c == 0)
		return (str + ft_strlen(str));
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (str + i);
		i--;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		print_error("your map file must ending with .ber, check it");
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	check_av(char *str)
{
	int	d;
	int	i;

	i = 0;
	str = ft_strrchr(str, '.');
	if (!str)
		return ;
	d = ft_strncmp(&str[i], ".ber");
	if (d != 0)
		print_error("your map file must ending with .ber, check it");
}
