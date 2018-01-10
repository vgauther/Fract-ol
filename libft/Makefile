# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgauther <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 14:13:38 by vgauther          #+#    #+#              #
#    Updated: 2017/12/11 16:32:37 by vgauther         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

OBJ = ft_strdup.o ft_strcmp.o ft_strlen.o ft_strcpy.o ft_strncpy.o \
ft_strcat.o ft_strncat.o ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o \
ft_toupper.o ft_tolower.o ft_strncmp.o ft_atoi.o ft_bzero.o ft_memcpy.o \
ft_memmove.o ft_memcmp.o ft_strlcat.o ft_isascii.o ft_isalnum.o ft_isalpha.o\
ft_isdigit.o ft_isprint.o ft_memccpy.o ft_memchr.o ft_memset.o ft_putchar.o \
ft_putstr.o ft_memalloc.o ft_memdel.o ft_strnew.o ft_strdel.o ft_strclr.o\
ft_striter.o ft_striteri.o ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o\
ft_strsub.o ft_strjoin.o ft_strtrim.o ft_strsplit.o ft_itoa.o ft_putendl.o \
ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o\
ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o ft_lstiter.o ft_lstmap.o

OBJ1 = $(addprefix src/, OBJ)

all: $(NAME)

%.o: src/%.c
	@gcc $(FLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "lib done"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY : clean fclean all re
