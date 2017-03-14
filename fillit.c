/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 22:02:58 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/10 06:49:56 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **ag)
{
	if (usage(ac) == 0)
		return (0);
	char buf[BUF_SIZE];
	ac = open(ag[1], O_RDONLY);
	ac = read(ac, buf, BUF_SIZE);
	
	ft_putendl(buf);
	return (0);
}

