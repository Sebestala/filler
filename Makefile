# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 13:58:01 by sgarcia           #+#    #+#              #
#    Updated: 2018/06/07 19:52:50 by sgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

HEADER = srcs/

DIR_S = srcs/

DIR_H = includes/

SRCS =		main.c			\
			algorithm.c		\
			algorithm2.c

DIR_LIBFT = libft/

LIBFT = libft.a

OBJS = $(addprefix $(DIR_S), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cd libft && cp libft.a ../filler.a
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(CC) $(CFLAGS) -o sgarcia.filler $(NAME)
	cp sgarcia.filler players/.

$(DIR_S)%.o: $(DIR_S)%.c $(DIR_H)filler.h
	@echo "compilation de $< \033[32m ok \033[0m"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT) :
	make -C $(DIR_LIBFT)

clean:
	make -C $(DIR_LIBFT) clean
	@rm -f $(OBJS)

fclean: clean
	make -C $(DIR_LIBFT) fclean
	@rm -f $(NAME)

re: fclean all
