/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 05:16:53 by aakin-al          #+#    #+#             */
/*   Updated: 2017/04/06 02:03:38 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		{
			ft_putendl("error");
			return (0);
		}
		tetriminos++;
	}
	return (1);
}

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
			map[len] = '\n';
		else
			map[len] = '.';
	}
	return (map);
}

void		place_tetrimino(char **m, char *tetrimino, int loc, int size)
{
	char	*map;
	int		col;
	int		row;
	int		count;

	map = *m;
	size++;
	row = (loc >= size) ? loc / size : 0;
	col = (loc < size) ? loc : loc % size;
	count = 0;
	while (*tetrimino)
	{
		if (count == 4)
		{
			row++;
			loc = col + row * size;
			(count == 4) ? (count = 0) : 0;
		}
		if (*tetrimino != '.')
			map[loc - 1] = *tetrimino;
		tetrimino++;
		loc++;
		count++;
	}
}

int			is_safe(char *map, char *tetrimino, int loc, int size)
{
	int		col;
	int		row;
	int		count;

	size++;
	row = (loc >= size) ? loc / size : 0;
	col = (loc < size) ? loc : loc % size;
	count = 0;
	while (*tetrimino)
	{
		if (count == 4)
		{
			row++;
			loc = col + row * size;
			(count == 4) ? (count = 0) : 0;
		}
		if (*tetrimino != '.' && map[loc - 1] != '.')
			return (0);
		tetrimino++;
		loc++;
		count++;
	}
	return (1);
}
