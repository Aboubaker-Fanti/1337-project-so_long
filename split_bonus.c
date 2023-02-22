/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afanti <afanti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:34:48 by afanti            #+#    #+#             */
/*   Updated: 2023/02/19 10:40:33 by afanti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	count_word(char const *str, char c)
{
	int	i;

	i = 0;
	while (*str && *str == c)
		str++;
	while (*str)
	{
		if (*str != c && (*(str + 1) == c || *(str + 1) == '\0'))
			i++;
		str++;
	}
	return (i);
}

static int	wordlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*malstr(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * wordlen(str, c) + 1);
	if (word == '\0')
		return (NULL);
	while (str[i] && str[i] != c)
	{
		word[i] = (char)str[i];
			i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**freey(char **str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char *s, char c, int size)
{
	char	**spl;
	size_t	i;
	size_t	x;

	if (!s)
		return (NULL);
	check_new_line(s, size);
	x = count_word(s, c);
	i = 0;
	spl = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!spl)
		return (NULL);
	while (i < x)
	{
		while (*s && *s == c)
			s++;
		spl[i] = malstr(s, c);
		if (!spl[i])
			return (freey(spl, i));
		while (*s && *s != c)
			s++;
		i++;
	}
	spl[i] = NULL;
	return (spl);
}
