# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 21:58:50 by hshimizu          #+#    #+#              #
#    Updated: 2023/08/19 23:12:06 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
LIBFT_H		= libft.h
DIR			= .
OBJS_DIR	= $(DIR)/objs

SRCS 		= \
	$(addprefix $(DIR)/, \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
	)

OBJECTS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

SRCS_BONUS	= \
	$(addprefix $(DIR)/, \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
	)

OBJECTS_BONUS = $(addprefix $(OBJS_DIR)/, $(SRCS_BONUS:.c=.o))

SRCS_EXTENSION	= \
	$(addprefix $(DIR)/, \
		ft_abs.c \
		ft_average.c \
		ft_sort.c \
		ft_issorted.c\
		ft_max.c \
		ft_min.c \
		ft_distory.c \
		ft_digit.c \
	)

OBJECTS_EXTENSION = $(addprefix $(OBJS_DIR)/, $(SRCS_EXTENSION:.c=.o))

CFLAGS		= -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus extension test

$(NAME): $(OBJECTS)
	$(AR) rc $@ $^

bonus: $(OBJECTS_BONUS)
	$(AR) rc $(NAME) $^

extension: $(OBJECTS_EXTENSION)
	$(AR) rc $(NAME) $^

$(OBJS_DIR)/%.o: %.c $(LIBFT_H)
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME) bonus extension

test: test.c all
	$(CC) -g $< $(NAME) -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all
