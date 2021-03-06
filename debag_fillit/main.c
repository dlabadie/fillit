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

int				output(t_solve_space *solve_space, unsigned int cur_size)
{
	int i;
	int j;

	i = -1;
	while(++i < cur_size)
	{
		j = -1;
		while (++j < cur_size)
		{
			if (SS->map[i * cur_size + j] >= 'A' && SS->map[i * cur_size + j] <= 'Z')
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
	return (ft_sqrt(tet_num * 4));
}

unsigned int	estimate_max(unsigned int tet_num)
{
	return (tet_num * 4);
}

int				search_invalid_ch(t_input_space *i_s)
{
	char *line;

	line = i_s->line;
	if (line == NULL)
		return (-1);
	while (*line)
	{
		if ((*line) != '#' && (*line) != '.')
			return (0);
		if ((*line) == '#')
			i_s->imp_char++;
		line++;
	}
	return (1);
}

int				create_int(USI *positions, USI *result)
{
	int i;

	if (!positions)
		return (-11);
	(*result) = 0;
	i = -1;
	while (++i != 4)
		(*result) |= 1 << (15 - positions[i]);
	return (11);
}

int				shift_upper_left(USI *positions)
{
	USI top;
	USI left;
	int i;

	if (!positions)
		return (-21);
	i = -1;
	top = positions[0];
	left = positions[0];
	while (++i < 4)
	{
		if ((positions[i] % 4) < (left % 4))
			left = positions[i];
	}
	i = -1;
	while (++i < 4)
	{
		positions[i] -= top / (USI)4 * (USI)4;
		positions[i] -= left % (USI)4;
	}
	return (21);
}

int				search_pos(char *tetramino, USI *positions)
{
	int i;
	int j;

	i = -1;
	j = -1;
	if (!tetramino || !positions)
		return (-31);
	while (*(tetramino + ++i))
	{
		if (*(tetramino + i) == '#')
		{
			j++;
			if (j > 4)
				return (30);
			positions[j] = i;
		}
	}
	return (31);
}
//TODO проверить базу - есть не все элементы
int				init_base(USI *base)
{
	if (!base)
		return (-41);
	base[0] = 9584;
	base[1] = 11776;
	base[2] = 17600;
	base[3] = 19520;
	base[4] = 19968;
	base[5] = 27648;
	base[6] = 34952;
	base[7] = 35008;
	base[8] = 35904;
	base[9] = 35968;
	base[10] = 36352;
	base[11] = 50240;
	base[12] = 50688;
	base[13] = 51328;
	base[14] = 52224;
	base[15] = 57856;
	base[16] = 58368;
	base[17] = 59392;
	base[18] = 61440;
	return (41);
}

int				search_in_base(int tetramino)
{
	int i;
	USI base[19];
	int err;

	err = init_base(base);
	if (err != 41)
		return (err);
	i = 0;
	while (i < 19)
	{
		if (tetramino == base[i++])
			return (51);
	}
	return (50);
}

int				tet_to_array(USI *tets, USI *size_tets, char *tetramino)
{
	USI positions[4];
	int err;
	USI int_tet;

	if (!tets || !size_tets)
		return (-61);
	if ((err = search_pos(tetramino, positions)) != 31)
		return (err);
	if ((err = shift_upper_left(positions)) != 21)
		return (err);
	if (err = create_int(positions, &int_tet) != 11)
		return (err);
	if ((err = search_in_base(int_tet) == 51))
	{
		tets[*size_tets] = int_tet;
		(*size_tets)++;
		return (61);
	}
	else
		return (err);
}

int				input_array(t_input_space *i_s)
{
	i_s->block = 0;
	i_s->imp_char = 0;
	while (get_next_line(i_s->fd, &(i_s->line)) == 1)
	{
		i_s->line_size = ft_strlen(i_s->line);
		i_s->block++;
		if (i_s->block == 5)
		{
			if (i_s->line_size)
				return (70);
			ft_strclr(i_s->tetramino);
			i_s->block = 0;
			i_s->imp_char = 0;
		}
		else
			if ((i_s->line_size != 4) || (search_invalid_ch(i_s) != 1) || (i_s->imp_char > 4))
				return (70);
		ft_strcat(i_s->tetramino, i_s->line);
		if (i_s->block == 4)
			if ((i_s->err = tet_to_array(i_s->tets, &(i_s->size_tets), i_s->tetramino) != 61))
				return (i_s->err);
	}
	if (i_s->block != 4)
		return (70);
	return (71);
}

int				die(char *str)
{
	ft_putendl(str);
	return (1);
}

void			init_SS(t_input_space IS, t_solve_space **SS)
{
	*SS = ft_memalloc(sizeof(t_solve_space));
	(*SS)->abs_size = estimate_max(IS.size_tets);
	(*SS)->map = ft_memalloc(sizeof(char) * ((*SS)->abs_size * (*SS)->abs_size + 1));
	(*SS)->tet_num = IS.size_tets;
	(*SS)->tetramino = (USI*) malloc(sizeof(USI) * (*SS)->tet_num);
	ft_memcpy((*SS)->tetramino, IS.tets, (IS.size_tets + 1) * sizeof(USI));
}

int				main(int argc, char *argv[])
{
	t_input_space		IS;
	t_solve_space		*SS;
	int					i;

	IS.size_tets = 0;
	if (argc != 2)
		return (die("usage: ./fillit [input_file]"));
	IS.fd = open(argv[1], O_RDONLY);
	if (input_array(&IS) != 71)
	{
		close(IS.fd);
		return (die("error"));
	}
	init_SS(IS, &SS);
	i = estimate_min(SS->tet_num) - 1;
	while (i++ <= SS->abs_size)
	{
		if (solver(SS, 0, 0, i))
		{
			output(SS, i);
			exit(0);
		}
	}
	return (0);
}
