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
# include <string.h>

void		ft_putendl(char const *s);
int			isvalid(char *str);
int			usage(int ac);
void		ft_putnbr(int c);
char		**ft_split(char const *s, char c);
int			ft_strinstr(const char *big, const char *little);
int			check(char **str);
char		*gen_1_map(int size);
char		*get_pattern(char *str);
void		place_tetrimino(char **map, char *tetrimino, int loc, int size);
int			is_safe(char *map, char *tetrimino, int loc, int size);
char		*ft_strdup(const char *s1);
int			ft_isalpha(int c);
void		remove_tetrimino(char **m, char *tetr);
int			num_tets(char **tetriminos);
int			ft_m_sqrt(int n);
int			solve(char **map, char **tet, int map_size);
char		**config_tets(char **tets);
int			until(char **map, char **tet, int map_size);
int			get_ntet(char const *str, char delim);
void		ft_putstr(char *str);
void		*ft_memalloc(size_t size);

#endif
