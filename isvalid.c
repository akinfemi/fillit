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
	patterns[0] = "###.\n..#";
	patterns[1] = ".#..\n.#..\n##";
	patterns[2] = "#...\n###";
	patterns[3] = "##..\n#...\n#";
	patterns[4] = "###.\n#";
	patterns[5] = "##..\n.#..\n.#";
	patterns[6] = "..#.\n###";
	patterns[7] = "#...\n#...\n##";
	patterns[8] = "###.\n.#";
	patterns[9] = ".#..\n##..\n.#";
	patterns[10] = ".#..\n###";
	patterns[11] = "#...\n##..\n#";
	patterns[12] = ".##.\n##";
	patterns[13] = "#...\n##..\n.#";
	patterns[14] = "##..\n##";
	patterns[15] = "#...\n#...\n#...\n#";
	patterns[16] = "####";
	patterns[17] = ".#..\n##..\n#";
	patterns[18] = "##..\n.##";
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