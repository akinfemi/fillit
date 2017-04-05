/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 22:02:58 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/24 14:35:01 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **ag)
{
	char	**tetris;
	char	*map;
	int		map_size;
	char	buf[BUF_SIZE];

	if (usage(ac) == 0)
		return (0);
	ac = read(open(ag[1], O_RDONLY), buf, BUF_SIZE);
	if (!(tetris = ft_split(buf, '\n')) || check(tetris) == 0)
		return (0);
	map_size = ft_m_sqrt(4 * get_ntet(buf, '\n'));
	map = gen_1_map(map_size);
	tetris = config_tets(tetris);
	if (until(&map, tetris, map_size))
		ft_putstr(map);
	else
		ft_putendl("No solution");
	return (0);
}

int		ft_m_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

char	**config_tets(char **tet)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (tet[++i] != '\0')
		tet[i] = get_pattern(tet[i]);
	i = 0;
	while (tet[i] != '\0')
	{
		while (tet[i][j] != '\0')
		{
			(tet[i][j] == '#') ? (tet[i][j] += 30 + i) : (tet[i][j] += 0);
			j++;
		}
		j = 0;
		i++;
	}
	return (tet);
}
