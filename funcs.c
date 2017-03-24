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
