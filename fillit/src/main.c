/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                			    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:26:25 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/02/18 15:52:31 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		init_ss(t_input_space IS, t_solve_space **SS)
{
	*SS = ft_memalloc(sizeof(t_solve_space));
	(*SS)->abs_size = estimate_max(IS.size_tets);
	(*SS)->map = ft_memalloc(sizeof(char) * ((*SS)->abs_size * \
	(*SS)->abs_size + 1));
	(*SS)->tet_num = IS.size_tets;
	(*SS)->tetramino = (USI*)malloc(sizeof(USI) * (*SS)->tet_num);
	ft_memcpy((*SS)->tetramino, IS.tets, (IS.size_tets + 1) * sizeof(USI));
}

static void		free_ss(t_solve_space **solve_space)
{
	free((*SS)->tetramino);
	free((*SS)->map);
	free(*SS);
}
static int		show_close(t_solve_space **SS, t_input_space IS, unsigned int i)
{
	output(*SS, i);
	close(IS.fd);
	free_ss(solve_space);
	return (0);
}
int				main(int argc, char *argv[])
{
	t_input_space		input_space;
	t_solve_space		*solve_space;
	unsigned int		i;

	IS.size_tets = 0;
	if (argc != 2)
		return (die("usage: ./fillit [input_file]"));
	IS.fd = open(argv[1], O_RDONLY);
	if (input_array(&IS) != 71)
	{
		close(IS.fd);
		return (die("error"));
	}
	init_ss(IS, &SS);
	i = estimate_min(SS->tet_num) - 1;
	while (i++ <= SS->abs_size)
	{
		if (solver(SS, 0, 0, i))
			return (show_close(&SS, IS, i));
	}
	return (0);
}