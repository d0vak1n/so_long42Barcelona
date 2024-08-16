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
CC=gcc -g
CFLAGS=-Wall -Wextra## -Werror
MLXFLAGS= -L./minilibx_linux -lmlx -lXext -lX11

## Source files
FILES=so_long.c test.c
FOLDER=src/

## Libft
LIBFT_DIR=./libft
LIBFT=$(LIBFT_DIR)/libft.a

## Libftprintf
LIBFTPRINTF_DIR=./ft_printf
LIBFTPRINTF=$(LIBFTPRINTF_DIR)/ft_printf

OBJS=$(patsubst %.c, $(FOLDER)%.o, $(FILES))

$(NAME): minilibx_linux $(LIBFT) $(OBJS) Makefile $(FOLDER)lib_so_long.h
	@echo "\n📝 Compiling program $(NAME) ... 📝\n"
	$(CC) -o $(NAME) $(OBJS) $(MLXFLAGS) -L$(LIBFT_DIR) -lft
	@echo "\n📖 $(NAME) created succesfully 📖\n"
	
minilibx_linux:
	@echo "\n- Importing minilibX, libft, ftprintf, get_next_line ... -\n"
	@git submodule update --init --recursive
	@cd minilibx_linux && make && ./configure && cd ..
	@echo "\n- MinilibX imported succesfully -\n"

$(LIBFT):
	@echo "\n- Compiling libft ... -\n"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "\n- Libft compiled succesfully -\n"


all: $(NAME)

%.o: $(FOLDER)%.c
	$(CC) $(CFLAGS) -c $^

.PHONY: all clean fclean re

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\n 🗑 All .o deleted 🗑\n"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\n 🗑 $(NAME) deleted 🗑\n"

re: fclean all
	@echo "\n🔁 Relinked 🔁\n"
