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

#include <string.h>

static int contains(const char *big, const char *small)
{
    while (*big && *small && (*big == *small))
    {
        big++;
        small++;
        if (*small == '\0')
        {
            return (1);
        }
    }
    return (0);
}

char        *ft_strstr(const char *big, const char *little)
{
    char    *ptr;

    ptr = NULL;
    if (*little == '\0')
        return ((char *) big);
    while (*big && *little)
    {
        if (*big == *little && contains(big, little) == 1)
		{
            ptr = (char *) big;
			return (ptr);
		}
        big++;
    }
    return (ptr);
}