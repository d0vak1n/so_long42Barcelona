# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramoreno <ramoreno@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 12:31:03 by ramoreno          #+#    #+#              #
#    Updated: 2024/05/06 12:31:10 by ramoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
## Name of the program
NAME=so_long

## Compile flags
CC=gcc
CFLAGS=-Wall -Wextra -Werror
XFLAGS=-lmlx -lXext -lX11

## Source files
FILES=so_long.c

OBJS=$(patsubst %.c, %.o, $(FILES))

$(NAME): $(OBJS) Makefile lib_so_long.h
	@echo "\n📝 Compiling program $(NAME) ... 📝\n"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(XFLAGS)
	@echo "\n📖 $(NAME) created succesfully 📖\n"

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

.PHONY: all clean fclean re

clean:
	@rm -f $(OBJS)
	@echo "\n 🗑 All .o deleted 🗑\n"

fclean: clean
	@rm -rf $(NAME)
	@echo "\n 🗑 All .a deleted 🗑\n"

re: fclean all
	@echo "\n🔁 Relinked 🔁\n"
