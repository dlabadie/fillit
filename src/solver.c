/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 23:54:04 by dlabadie          #+#    #+#             */
/*   Updated: 2019/02/06 13:20:04 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int				erase_tetramino(t_solve_space *solve_space,
										  unsigned int place,
										  unsigned int cur_tet,
										  unsigned int cur_size)
{
	unsigned char		i;
	unsigned char		j;
	USI					mask;

	mask = 1 << 15;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (mask & *(SS->tetramino + cur_tet))
			{
				SS->map[place + i * cur_size + j] = '\0';
			}
			mask = mask >> 1;
			j++;
		}
		i++;
	}
	return (0);
}

static int				fill_place(t_solve_space *solve_space,
									 unsigned int place,
									 unsigned int cur_tet,
									 unsigned int cur_size)
{
	unsigned char		i;
	unsigned char		j;
	USI					mask;

	mask = 1 << 15;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (mask & *(SS->tetramino + cur_tet))
			{
				SS->map[place + i * cur_size + j] = 'A' + cur_tet;
			}
			mask = mask >> 1;
			j++;
		}
		i++;
	}
	return (0);
}

static int				check_place(t_solve_space *solve_space,
									  unsigned int place,
									  unsigned int cur_tet,
									  unsigned int cur_size)
{
	unsigned char		i;
	unsigned char		j;
	USI					mask;

	mask = 1 << 15;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (mask & *(SS->tetramino + cur_tet))
			{
				if (place + i * cur_size + j >= cur_size * cur_size || \
					SS->map[place + i * cur_size + j] != '\0' || \
					place % cur_size + j >= cur_size)
					return (0);
			}
			mask = mask >> 1;
			j++;
		}
		i++;
	}
	fill_place(solve_space, place, cur_tet, cur_size);
	return (1);
}

static unsigned int		find_place(t_solve_space *solve_space,
									  unsigned int *place,
									  unsigned int cur_tet,
									  unsigned int cur_size)
{
	if (*place >= cur_size * cur_size)
		return (0);
	else if (check_place(solve_space, *place, cur_tet, cur_size))
		return (1);
	else
	{
		*place = *place + 1;
		return (find_place(solve_space, place, cur_tet, cur_size));
	}
	return (0);
}

int						solver(t_solve_space *solve_space,
								  unsigned int place,
								  unsigned int cur_tet,
								  unsigned int cur_size)
{
	if (cur_tet == SS->tet_num)
		return (1);
	else if (find_place(solve_space, &place, cur_tet, cur_size) == 0)
		return (0);
	else
	{
		if (solver(solve_space, 0, cur_tet + 1, cur_size))
			return (1);
		else
		{
			erase_tetramino(solve_space, place, cur_tet, cur_size);
			return (solver(solve_space, place + 1, cur_tet, cur_size));
		}
	}
	return (0);
}