/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:26:25 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/02/18 15:52:31 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# include "../libft/libft.h"

# define SS solve_space
# define IS input_space
# define USI unsigned short int

typedef struct		s_solve_space
{
	char			*map;
	unsigned int	abs_size;
	USI				*tetramino;
	unsigned int	tet_num;
}					t_solve_space;

typedef struct		s_input_space
{
	USI				tets[26];
	USI				size_tets;
	int				fd;
	USI				block;
	char			*line;
	size_t			line_size;
	char			tetramino[17];
	int				err;
	int 			imp_char;
}					t_input_space;

int					solver(t_solve_space *solve_space,
							unsigned int place,
							unsigned int cur_tet,
							unsigned int cur_size);
void					output(t_solve_space *solve_space,
							unsigned int cur_size);
unsigned int		estimate_min(unsigned int tet_num);
unsigned int		estimate_max(unsigned int tet_num);
int					die(char *str);
int					input_array(t_input_space *i_s);
int					create_int(const USI *positions, USI *result);
int					shift_upper_left(USI *positions);
int					search_invalid_ch(t_input_space *i_s);
int					search_pos(const char *tetramino, USI *positions);

#endif