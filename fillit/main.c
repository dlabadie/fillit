#include "libft.h"
#include <stdio.h>

#define USI unsigned short int

int	search_invalid_ch(char *line)
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

int	create_int(USI *positions, USI *result)
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

int	shift_upper_left(USI *positions)
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

int	search_pos(char *tetramino, USI *positions)
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

int	init_base(USI *base)
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

int	search_in_base(int tetramino)
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

int	tet_to_array(USI *tets, USI *size_tets, char *tetramino)
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

int	input_array(USI *tets, USI *size_tets, int fd)
{
	USI		block;
	char	*line;
	size_t	line_size;
	char	tetramino[17];
	int		err;

	if (!tets || !size_tets)
		return (-71);
	block = 0;
	while (get_next_line(fd, &line) == 1)
	{
		line_size = ft_strlen(line);
		block++;
		if (block == 5)
		{
			if (line_size)
			{
				free(line);
				return (70);
			}
			ft_strclr(tetramino);
			block = 0;
		}
		else
		{
			if ((line_size != 4) || (search_invalid_ch(line) != 1))
			{
				free(line);
				return (70);
			}
		}
		ft_strcat(tetramino, line);
		free(line);
		if (block == 4)
		{
			if ((err = tet_to_array(tets, size_tets, tetramino) != 61))
				return (err);
		}
	}
	if (block != 4)
		return (70);
	return (71);
}

int			main(int argc, char *argv[])
{
	int		fd;
	USI	 tets[26];
	USI	 size_tets;


	size_tets = 0;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	printf("\nfunc rez %d\n", input_array(tets,  &size_tets, fd));


	if (argc == 2)
		close(fd);
	return 0;
}
