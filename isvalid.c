/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 23:57:29 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/04 00:11:49 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		isvalid(char *str)
{
	int		i;
	int		block;
	int		count;

	i = 0;
	block = 0;
	count = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '#')
			block++;
		if (str[i] == '.' || str[i] == '#')
			count++;
		if ((str[i] == '\n' || str[i] == '\0') && count != 4)
			return (0);
		if (str[i] == '\n' && count == 4)
			count = 0;
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		i++;
	}
	if (i != 19 || block != 4 || (pattern(str) == 0))
		return (0);
	return (1);
}

int		pattern(char *str)
{
	
}