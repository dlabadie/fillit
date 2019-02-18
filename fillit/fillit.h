/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:31:43 by dlabadie          #+#    #+#             */
/*   Updated: 2018/12/17 21:31:46 by dlabadie         ###   ########.fr       */
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

# include "libft/libft.h"

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
}					t_input_space;

int					solver(t_solve_space *solve_space,
						   unsigned int place,
						   unsigned int cur_tet,
						   unsigned int cur_size);

unsigned int		estimate_max(unsigned int tet_num);
unsigned int		estimate_min(unsigned int tet_num);



/*
 
1
 *...
 **..
 *...
 ....
 1000110010000000
 35968
 
2
 .*..
 ***.
 ....
 ....
 0100111000000000
 19968
 
3
 .*..
 **..
 .*..
 ....
 0100110001000000
 19520
 
4
 ***.
 .*..
 ....
 ....
 1110010000000000
 58368
 
5
 *...
 *...
 *...
 *...
 1000100010001000
 34952
 
6
 ****
 ....
 ....
 ....
 1111000000000000
 61440
 
7
 ***.
 *...
 ....
 ....
 1110100000000000
 59392
 
8
 *...
 *...
 **..
 ....
 1000100011000000
 35008
 
9
 ..*.
 ***.
 ....
 ....
 0010111000000000
 11776
 
10
 **..
 .*..
 .*..
 ....
 1100010001000000
 50240
 
11
 ***.
 ..*.
 ....
 ....
 1110001000000000
 57856
 
12
 **..
 *...
 *...
 ....
 1100100010000000
 51328
 
13
 *...
 ***.
 ....
 ....
 1000111000000000
 36352
 
14
 .*..
 .*..
 **..
 ....
 0100010011000000
 17600
 
15
 **..
 **..
 ....
 ....
 1100110000000000
 52224
 
16
 **..
 .**.
 ....
 ....
 1100011000000000
 50688
 
17
 .*..
 **..
 *...
 ....
 0100110010000000
 19584
 
18
 .**.
 **..
 ....
 ....
 0110110000000000
 27648
 
19
 *...
 **..
 .*..
 ....
 1000110001000000
 35904
 
 */

#endif
