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

void				output(t_solve_space *solve_space, unsigned int cur_size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < cur_size)
	{
		j = 0;
		while (j < cur_size)
		{
			if (SS->map[i * cur_size + j] >= 'A'
				&& SS->map[i * cur_size + j] <= 'Z')
				ft_putchar(SS->map[i * cur_size + j]);
			else if (SS->map[i * cur_size + j] == '\0')
				ft_putchar('.');
			else
			{
				ft_putchar('\n');
				ft_putchar(SS->map[i * cur_size + j]);
				ft_putchar('\n');
			}
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

unsigned int		estimate_min(unsigned int tet_num)
{
	return (ft_sqrt(tet_num * 4));
}

unsigned int		estimate_max(unsigned int tet_num)
{
	return (tet_num * 4);
}

int					die(char *str)
{
	ft_putendl(str);
	return (1);
}
