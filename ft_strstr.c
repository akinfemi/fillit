/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:11:25 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/01 13:34:08 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	contains(const char *big, const char *small)
{
	while (*big && *small && (*big == *small))
	{
		if (*(big + 1) == '\n')
			big++;
		big++;
		small++;
		if (*small == '\0')
		{
			return (1);
		}
	}
	return (0);
}

int			ft_strinstr(const char *big, const char *little)
{
	while (*big && *little)
	{
		if (*big == *little && contains(big, little) == 1)
			return (1);
		big++;
	}
	return (0);
}
