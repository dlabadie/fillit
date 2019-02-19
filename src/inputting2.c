/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputting2.c                                	    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekedge-w <ekedge-w@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:26:25 by ekedge-w          #+#    #+#             */
/*   Updated: 2019/02/18 15:52:31 by ekedge-w         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		create_int(const USI *positions, USI *result)
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

int		shift_upper_left(USI *positions)
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

int		search_invalid_ch(char *line)
{
	if (line == NULL)
		return (-1);
	while (*line)
	{
		if ((*line) != '#' && (*line) != '.')
			return (0);
		line++;
	}
	return (1);
}

int		search_pos(const char *tetramino, USI *positions)
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
			positions[j] = (USI) i;
		}
	}
	return (31);
}