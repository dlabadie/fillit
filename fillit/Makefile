# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/30 10:27:53 by dlabadie          #+#    #+#              #
#    Updated: 2019/02/07 14:17:49 by dlabadie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

CFILES		= main.c solver.c inputting1.c inputting2.c helpers.c

OFILES		= $(addprefix $(ODIR),$(CFILES:.c=.o))

CC		= gcc
FLAGS	= -Wall -Wextra -Werror

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

SDIR	= ./src/
IDIR	= ./includes/
ODIR	= ./obj/

all: $(NAME)

obj:
	mkdir -p $(ODIR)

$(ODIR)%.o:$(SDIR)%.c
	gcc $(FLAGS)  $(FT_INC) -I $(IDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)



$(NAME): obj $(FT_LIB) $(OFILES)
	$(CC) $(FLAGS) $(OFILES)  $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(ODIR)
	make -C $(FT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY : all clean fclean re 