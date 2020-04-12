NAME = fdf
NAME_SOURCES = parse_line.c utils.c main.c rotate.c control.c draw.c init.c keys.c menu.c read_file.c
PATH_SRCS = ./srcs/
SRC = $(addprefix $(PATH_SRCS),$(NAME_SOURCES))
FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
INCLUDE = ./includes

all: $(NAME) 

$(NAME): $(SRC)
	@make -C libft/
	@make -C minilibx_macos/
	@gcc $(FLAGS) -o $(NAME) $(SRC) -I$(INCLUDE) -L.  libft/libft.a minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re