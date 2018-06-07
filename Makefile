# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgarcia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 13:58:01 by sgarcia           #+#    #+#              #
#    Updated: 2018/06/07 19:08:36 by sgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler.a

CFLAGS = -Wall -Wextra -Werror

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
	@ar rc $(NAME) $(OBJS)
#@ranlib $(NAME)

$(DIR_S)%.o: $(DIR_S)%.c $(DIR_H)filler.h
	@echo "compilation de $< \033[32m ok \033[0m"
	@$(CC) $(CFLAGS) -o sgarcia.filler -c $<
	cp sgarcia.filler players/.

$(LIBFT) :
	make -C $(DIR_LIBFT)
	cp $(DIR_LIBFT)/$(LIBFT) ./$(NAME)
clean:
	make -C $(DIR_LIBFT) clean
	@rm -f $(OBJS)

fclean: clean
	make -C $(DIR_LIBFT) fclean
	@rm -f $(NAME)

re: fclean all
