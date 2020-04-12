# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eberta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 16:29:48 by eberta            #+#    #+#              #
#    Updated: 2019/10/16 15:03:08 by eberta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isnumber_base.c ft_isspace.c ft_atoi_base.c get_next_line.c ft_str_replace.c ft_str_is_printable.c ft_isprint.c ft_memccpy.c ft_putnbr.c ft_strequ.c ft_strnequ.c ft_isupper.c ft_memchr.c ft_putnbr_fd.c ft_striter.c ft_strnew.c ft_atoi.c ft_itoa.c ft_memcmp.c ft_putstr.c ft_striteri.c ft_strnstr.c ft_bzero.c ft_lstadd.c ft_memcpy.c ft_putstr_fd.c ft_strjoin.c ft_strrchr.c ft_charind.c ft_lstaddtail.c ft_memdel.c ft_strcat.c ft_strlcat.c ft_strsplit.c ft_lstdel.c ft_memmove.c ft_strchr.c ft_strlen.c ft_strstr.c ft_isalnum.c ft_lstdelone.c ft_memset.c ft_strclr.c ft_strmap.c ft_strsub.c ft_isalpha.c ft_lstiter.c ft_putchar.c ft_strcmp.c ft_strmapi.c ft_strtrim.c ft_isascii.c ft_lstmap.c ft_putchar_fd.c ft_strcpy.c ft_strncat.c ft_tolower.c ft_isdigit.c ft_lstnew.c ft_putendl.c ft_strdel.c ft_strncmp.c ft_toupper.c ft_islower.c ft_memalloc.c ft_putendl_fd.c ft_strdup.c ft_strncpy.c

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(SRC) libft.h 
	@gcc -Wall -Wextra -Werror -c $(SRC) libft.h
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ) libft.h.gch

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
