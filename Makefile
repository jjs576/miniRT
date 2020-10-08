# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 14:04:40 by jjoo              #+#    #+#              #
#    Updated: 2020/10/08 11:48:26 by jjoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	miniRT
SRCS	=	$(wildcard srcs/*.c)
OBJS	=	$(SRCS:.c=.o)
INCS	=	includes

CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -rf

MMS		=	libs/minilibx_mms_20200219
OPENGL	=	libs/minilibx_opengl_20191021

LIBMLX	=	libmlx.dylib libmlx.a

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -I $(INCS) -c $< -o $@

$(LIBMLX):
	@$(MAKE) -C ./$(MMS)
	@$(MAKE) -C ./$(OPENGL)
	@cp ./$(MMS)/libmlx.dylib .
	@cp ./$(OPENGL)/libmlx.a .

$(NAME): $(OBJS) $(LIBMLX)
	$(CC) $(FLAGS) -I $(INCS) $(LIBMLX) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(MMS) clean
	$(MAKE) -C $(OPENGL) clean
	$(RM) $(LIBMLX)
	$(RM) $(NAME)

re: fclean all

bonus: all
