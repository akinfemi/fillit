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

	if (usage(ac) == 0)
		return (0);
	char buf[BUF_SIZE];
	ac = read(open(ag[1], O_RDONLY) , buf, BUF_SIZE);
	if (!(tetris = ft_split(buf, '\n')) || check(tetris) == 0)
		return (0);
	ft_putendl(*tetris);
	return (0);
}
