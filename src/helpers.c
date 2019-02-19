/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:50:45 by dlabadie          #+#    #+#             */
/*   Updated: 2019/02/18 20:51:05 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				output(t_solve_space *solve_space, unsigned int cur_size)
{
	int i;
	int j;

	i = -1;
	while ((unsigned int)(++i) < cur_size)
	{
		j = -1;
		while ((unsigned int)(++j) < cur_size)
		{
			if (SS->map[i * cur_size + j] >= 'A' && \
				SS->map[i * cur_size + j] <= 'Z')
				printf("%c", SS->map[i * cur_size + j]);
			else if (SS->map[i * cur_size + j] == '\0')
				printf(".");
			else
				printf("\n%i\n", SS->map[i * cur_size + j]);
		}
		printf("\n");
	}
	return (0);
}

unsigned int	estimate_min(unsigned int tet_num)
{
	unsigned int	es;

	es = ft_sqrt(tet_num * 4);
	return ((es < 4) ? 4 : es);
}

unsigned int	estimate_max(unsigned int tet_num)
{
	return (tet_num * 4);
}

int				die(char *str)
{
	ft_putendl(str);
	return (1);
}