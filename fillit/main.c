#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
# define USI unsigned short int

static  short int search_invalid_ch(char *line, size_t line_size)
{
    if (line == NULL)
        return (-1);
        while (*line)
        {
            if (*line != '#' || *line != '.')
                return  (0);
        }
    return (1);
}
short int input_tets(USI *tets, USI *size_tets, int fd)
{
    USI     block;
    char    *line;
    size_t  line_size;

    block = 0;
    *size_tets = 26;
    tets = (USI *)malloc(sizeof(USI) * (*size_tets));
    //TODO  подумать над тем чтобы создать функцию reading and cheking  из этого  вайла
    while (get_next_line(fd, &line) == 1)
    {
        //TODO блок провекри на структурность ввода - в отдельную функцию
        line_size = ft_strlen(line);
        block++;
        if (block == 5)
        {
            if (!line_size)
            {
                free(tets);
                return (0);
            }
            block = 0;
        }
        else
            block = 0;
        if (line_size != 4)
        {
            free(tets);
            return (0);
        }
        //TODO закончила на провекре валидности символов
    }

}
int main(int argc, char *argv[])
{
    int		fd;
    char	*line;

    if (argc == 1)
        fd = 0;
    else if (argc == 2)
        fd = open(argv[1], O_RDONLY);
    else
        return (2);
    while (get_next_line(fd, &line) == 1)
    {
        printf("%s\n",line);
        free(line);
    }
    if (argc == 2)
        close(fd);
    return 0;
}
