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

#include "fillit.h"

char **gen_patterns(char **patterns)
{
	patterns[0] = "###...#";
	patterns[1] = ".#...#..##";
	patterns[2] = "#...###";
	patterns[3] = "##..#...#";
	patterns[4] = "###.#";
	patterns[5] = "##...#...#";
	patterns[6] = "..#.###";
	patterns[7] = "#...#...##";
	patterns[8] = "###..#";
	patterns[9] = ".#..##...#";
	patterns[10] = ".#..###";
	patterns[11] = "#...##..#";
	patterns[12] = ".##.##";
	patterns[13] = "#...##...#";
	patterns[14] = "##..##";
	patterns[15] = "#...#...#...#";
	patterns[16] = "####";
	patterns[17] = ".#..##..#";
	patterns[18] = "##...##";
	patterns[19] = "\0";
	return (patterns);
}

int		isvalidpattern(char *str)
{
	char **patterns;
	int		i;
	
	i = -1;
	patterns = (char**)malloc(sizeof(char *) * 20);
	while (++i < 20)
		patterns[i] = (char *)malloc(sizeof(char) * 18);
	patterns = gen_patterns(patterns);
	while (*patterns)
	{
		if (ft_strinstr(str,*patterns) == 1)
			return (1);
		patterns++;
	}
	return (0);
}

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
	if (i != 19 || block != 4 || (isvalidpattern(str) == 0))
		return (0);
	return (1);
}

char		*get_pattern(char *str)
{
	char 	**patterns;
	int		i;
	char 	*tet;

	i = -1;
	tet = NULL;
	patterns = (char**)malloc(sizeof(char *) * 20);
	while (++i < 20)
		patterns[i] = (char *)malloc(sizeof(char) * 18);
	patterns = gen_patterns(patterns);
	i = 0;
	while (patterns[i])
	{
		if (ft_strinstr(str, patterns[i]) == 1)
		{
			tet = ft_strdup(patterns[i]);
			free(patterns);
			return (tet);
		}
		i++;
	}
	return (tet);
}
