/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 18:05:33 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/08 21:39:00 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*ans;
	int		i;

	i = -1;
	ans = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	ans = (char *)malloc(sizeof(char) * len + 1);
	if (!ans)
		return (0);
	while (*s1)
	{
		ans[++i] = *s1;
		s1++;
	}
	while (*s2)
	{
		ans[++i] = *s2;
		s2++;
	}
	ans[++i] = '\0';
	return (ans);
}
