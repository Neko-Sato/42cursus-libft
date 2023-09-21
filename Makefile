# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 21:58:50 by hshimizu          #+#    #+#              #
#    Updated: 2023/09/22 02:02:14 by hshimizu         ###   ########.fr        #
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
		ft_digit.c \
		ft_joinpath.c \
		ft_replace.c \
		ft_memdup.c \
		ft_xlstlen.c \
		ft_xlstat.c \
		ft_xlstappend.c \
		ft_xlstinsert.c \
		ft_xlstpop.c \
		ft_xlstclear.c \
		ft_xlst2array.c \
		ft_strdup2.c \
		ft_strjoin2.c \
		ft_strgennew.c \
		ft_strgendel.c \
		ft_strgenclearbuff.c \
		ft_strgenchr.c \
		ft_strgenstr.c \
		ft_strgencomp.c \
		ft_strgenfetch.c \
		ft_isspace.c \
		ft_bufferionew.c \
		ft_bufferiodel.c \
		ft_bufferioread.c \
		ft_read.c \
		ft_readline.c \
		ft_write.c \
	)

OBJECTS_EXTENSION = $(addprefix $(OBJS_DIR)/, $(SRCS_EXTENSION:.c=.o))

CFLAGS		= -Wall -Wextra -Werror -g

.PHONY: all clean fclean re bonus extension test norm

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
	$(CC) -g $< -L. -I. -lft -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm: $(LIBFT_H) $(SRCS) $(SRCS_BONUS) $(SRCS_EXTENSION)
	@norminette $^
