/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 05:18:43 by aakin-al          #+#    #+#             */
/*   Updated: 2017/03/24 14:31:11 by aakin-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/fcntl.h>
# include <unistd.h>
# define BUF_SIZE 4096
# include <stdlib.h>

void		ft_putendl(char const *s);
int			isvalid(char *str);
int			usage(int ac);
void		ft_putnbr(int c);
char		**ft_split(char const *s, char c);
int			ft_strinstr(const char *big, const char *little);
int			check(char **str);

#endif
