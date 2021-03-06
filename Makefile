# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 14:04:40 by jjoo              #+#    #+#              #
#    Updated: 2020/11/07 20:57:34 by jjoo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	miniRT
SRCS		=	$(wildcard srcs/*/*.c)
OBJS		=	$(SRCS:.c=.o)
INCS		=	includes

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

MMS			=	libs/minilibx_mms_20200219
FRAMEWORK	=	-framework OpenGl\
				-framework AppKit
LIBMLX		=	libmlx.dylib
all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -I $(INCS) -c $< -o $@

$(LIBMLX):
	@$(MAKE) -C ./$(MMS)
	@cp ./$(MMS)/libmlx.dylib .

$(NAME): $(LIBMLX) $(OBJS)
	$(CC) $(FLAGS) -I $(INCS) $(LIBMLX) $(FRAMEWORK) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(MMS) clean
	$(RM) $(LIBMLX)
	$(RM) $(NAME)

re: fclean all

bonus: all
