# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 13:59:27 by cyglardo          #+#    #+#              #
#    Updated: 2024/11/19 11:14:00 by cyglardo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c itoa.c itoa_base.c write.c 
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -I. -c $< -o $(<:.c=.o)

$(NAME): $(OBJ) ft_printf.h
	ar rcs $(NAME) $(OBJ) 

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY : all clean fclean re
