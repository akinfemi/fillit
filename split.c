/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 23:57:29 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/04 00:11:49 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			get_ntet(char const *str, char dl)
{
	int	i;

	i = 0;
	while (*str)
	{
		if ((*str == dl) && (*(str + 1) == dl || *(str + 1) == '\0'))
		{
			if ((*(str + 1) == dl) && (*(str + 2) == dl || *(str + 2) == '\0'))
				return (0);
			i++;
		}
		str++;
	}
	return (i);
}

static char	*next_tet(char const **st, char delim)
{
	int			i;
	char const	*str;
	char		*tet;

	i = 0;
	tet = 0;
	str = *st;
	while (*str == delim || *str == ' ' || *str == '\t')
		str++;
	while (!(str[i] == delim && (str[i + 1] == delim || str[i + 1] == '\0')))
		i++;
	tet = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (!(str[i] == delim && (str[i + 1] == delim || str[i + 1] == '\0')))
	{
		tet[i] = str[i];
		i++;
	}
	tet[i] = '\0';
	*st = str + i;
	return (tet);
}

char		**ft_split(char const *s, char c)
{
	char	**ans;
	int		n_tet;
	int		i;

	n_tet = get_ntet(s, c);
	if (n_tet == 0)
	{
		ft_putendl("error");
		return (0);
	}
	ans = 0;
	i = 0;
	ans = (char **)malloc(sizeof(char *) * n_tet + 1);
	if (!ans)
		return (0);
	while (i < n_tet)
	{
		ans[i] = next_tet(&s, c);
		i++;
	}
	ans[i] = 0;
	return (ans);
}
