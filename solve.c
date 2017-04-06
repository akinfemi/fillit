/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 01:59:49 by aakin-al          #+#    #+#             */
/*   Updated: 2017/04/06 01:59:51 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		until(char **map, char **tet, int map_size)
{
	while (!solve(map, tet, map_size))
	{
		free(*map);
		*map = NULL;
		map_size++;
		*map = gen_1_map(map_size);
	}
	return (1);
}

int		solve(char **m, char **tetrimino, int map_size)
{
	char	*map;
	int		loc;
	int		len;

	map = *m;
	loc = 1;
	len = map_size + map_size * map_size;
	if (!*tetrimino)
		return (1);
	while (loc < len)
	{
		if (is_safe(map, *tetrimino, loc, map_size))
		{
			place_tetrimino(&map, *tetrimino, loc, map_size);
			if (solve(&map, tetrimino + 1, map_size))
				return (1);
			else
				remove_tetrimino(&map, *tetrimino);
		}
		loc++;
	}
	return (0);
}
