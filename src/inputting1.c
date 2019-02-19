/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputting1.c                                	    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:26:25 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/02/18 15:52:31 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		init_base(USI *base)
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

static int		search_in_base(int tetramino)
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

static int		tet_to_array(USI *tets, USI *size_tets, char *tetramino)
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
	if ((err = create_int(positions, &int_tet)) != 11)
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
	while (ft_get_next_line(i_s->fd, &(i_s->line)) == 1)
	{
		i_s->line_size = ft_strlen(i_s->line);
		i_s->block++;
		if (i_s->block == 5)
		{
			if (i_s->line_size)
				return (70);
			ft_strclr(i_s->tetramino);
			i_s->block = 0;
		}
		else if ((i_s->line_size != 4) || (search_invalid_ch(i_s->line) != 1))
			return (70);
		ft_strcat(i_s->tetramino, i_s->line);
		if (i_s->block == 4)
			if ((i_s->err = tet_to_array(i_s->tets, &(i_s->size_tets), \
	i_s->tetramino) != 61))
				return (i_s->err);
	}
	if (i_s->block != 4)
		return (70);
	return (71);
}