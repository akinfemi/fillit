/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:04:38 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/22 17:02:12 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (alst == NULL)
		*alst = new;
	else
	{
		new->next = *alst;
		*alst = new;
	}
}
