/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 05:16:53 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/24 14:34:57 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fillit.h"

int			usage(int ac)
{
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit <filename>");
		return (0);
	}
	return (1);
}

int			check(char **tetriminos)
{
	while (*tetriminos)
	{
		if (isvalid(*tetriminos) == 0)
			return (0);
		tetriminos++;
	}
	return (1);
}
/*
char		**gen_map(size_t size)
{
	char	**map;
	size_t	i;
	int		j;

	i = 0;
	j = size;
	map = (char **)malloc(sizeof(char) * size + 1);
	map[size] = "\0";
	while (i < size)
	{
		j = size;
		map[i] = (char *)malloc(sizeof(char) * size + 1);
		map[i][size] = '\0';
		while (--j >= 0)
			map[i][j] = '.';
		printf("%s\n", map[i]);
		i++;
	}
	return (map);
}

void		place_tetrimino(char **map, int row, int col, char *tetrimino)
{
	int		x;
	int		y;

	x = row;
	y = col;
	while (*tetrimino)
	{
		if (*tetrimino == '.')
		{
			tetrimino++;
			x++;
		}
		else if (*tetrimino != '.' && map[x][y] == '.')
		{
			map[x][y] = *tetrimino;
			tetrimino++;
			x++;
		}
	}
}*/

char		*gen_1_map(int size)
{
	char	*map;
	int		len;

	len = size * size + size;
	map = (char *)malloc(sizeof(char) * len + 1);
	map[len] = '\0';
	while (--len >= 0)
	{
		if (len == size || (len - size) % (size + 1) == 0)
			map[len] ='\n';
		else
			map[len] = '.';
	}
	return (map);
}

void		place_tetrimino(char *map, char *tetrimino, int loc)
{
	while (*tetrimino)
	{
		if (*tetrimino == '.')
		{
			tetrimino++;
			loc++;
		}
		else
			map[loc] = *tetrimino;
	}
}

int			is_safe(char *map, char *tetrimino, int loc)
{
	while (*tetrimino)
	{
		if (*tetrimino != '.' && *tetrimino != '\n' && map[loc] != '.')
			return (0);
		tetrimino++;
	}
}
