# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjoo <jjoo@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/07 14:04:40 by jjoo              #+#    #+#              #
#    Updated: 2020/10/25 11:12:06 by jjoo             ###   ########.fr        #
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

LIBMLX	=	libmlx.dylib
all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -I $(INCS) -c $< -o $@

$(LIBMLX):
	@$(MAKE) -C ./$(MMS)
	@cp ./$(MMS)/libmlx.dylib .

$(NAME): $(OBJS) $(LIBMLX)
	$(CC) $(FLAGS) -I $(INCS) $(LIBMLX) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(MMS) clean
	$(RM) $(LIBMLX)
	$(RM) $(NAME)

re: fclean all

bonus: all
