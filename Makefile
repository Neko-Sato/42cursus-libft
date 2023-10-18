# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 21:58:50 by hshimizu          #+#    #+#              #
#    Updated: 2023/10/19 00:26:09 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
LIBFT_H		= libft.h
ROOT_DIR	= .
INCS_DIR	= $(ROOT_DIR)/include
OBJS_DIR	= $(ROOT_DIR)/objs

SRCS 		= \
	$(addprefix $(ROOT_DIR)/, \
		$(addprefix ft_array/, \
			ft_2darraydel.c \
			ft_2darraynew.c \
			ft_average.c \
			ft_issorted.c \
			ft_maxarray.c \
			ft_minarray.c \
			ft_sort.c \
			ft_sum.c \
			ft_all.c \
			ft_any.c \
		) \
		$(addprefix ft_bufferio/, \
			ft_bufferiodel.c \
			ft_bufferionew.c \
			ft_bufferioread.c \
			ft_read.c \
			ft_readline.c \
			ft_write.c \
		) \
		$(addprefix ft_ctype/, \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_tolower.c \
			ft_toupper.c \
		) \
		$(addprefix ft_lst/, \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
		) \
		$(addprefix ft_pathlib/, \
			ft_joinpath.c \
		) \
		$(addprefix ft_put_fd/, \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
		) \
		$(addprefix ft_stdlib/, \
			ft_abs.c \
			ft_atof.c \
			ft_atoi.c \
			ft_atol.c \
			ft_calloc.c \
			ft_realloc.c \
			ft_itoa.c \
			ft_utoa.c \
		) \
		$(addprefix ft_strgen/, \
			ft_strgenchr.c \
			ft_strgenclearbuff.c \
			ft_strgencomp.c \
			ft_strgendel.c \
			ft_strgenfetch.c \
			ft_strgennew.c \
			ft_strgenstr.c \
		) \
		$(addprefix ft_string/, \
			ft_bzero.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdup.c \
			ft_memmove.c \
			ft_memset.c \
			ft_memswap.c \
			ft_replace.c \
			ft_split.c \
			ft_strchr.c \
			ft_strcmp.c \
			ft_strdup.c \
			ft_strdup2.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strjoin2.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strnchr.c \
			ft_strncmp.c \
			ft_strnlen.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
		) \
		$(addprefix ft_utils/, \
			ft_digit.c \
			ft_isnumber.c \
			ft_max.c \
			ft_min.c \
			ft_sign.c \
		) \
		$(addprefix ft_xlst/, \
			ft_xlst2array.c \
			ft_xlstappend.c \
			ft_xlstat.c \
			ft_xlstclear.c \
			ft_xlstinsert.c \
			ft_xlstlen.c \
			ft_xlstpop.c \
			ft_xlstset.c \
		) \
		$(addprefix ft_complex/, \
			ft_cabs.c \
			ft_carg.c \
			ft_conj.c \
			ft_cadd.c \
			ft_csub.c \
			ft_cmul.c \
			ft_cdiv.c \
			ft_cexp.c \
			ft_cln.c \
			ft_cpow.c \
			ft_clog.c \
		)\
		$(addprefix ft_smalloc/, \
			ft_ssizeof.c \
			ft_smalloc.c \
			ft_sfree.c \
			ft_scalloc.c \
			ft_srealloc.c \
		)\
		$(addprefix ft_vector/, \
			ft_vector.c \
			ft_vector_del.c \
			ft_vector_size.c \
			ft_vector_sizeoftype.c \
			ft_vector_capacity.c \
			ft_vector_reserve.c \
			ft_vector_shrink_to_fit.c \
		)\
	)

OBJECTS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

CFLAGS		= -Wall -Wextra -Werror
# CFLAGS		+= -g
CFLAGS		+= -O2
IDFLAGS		+= -I$(INCS_DIR)

.PHONY: all clean fclean re bonus test norm

$(NAME): $(OBJECTS)
	$(AR) rc $@ $^

$(OBJS_DIR)/%.o: %.c $(LIBFT_H)
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $(IDFLAGS) $< -o $@

all: $(NAME)

bonus: $(NAME)

test: test.c all
	$(CC) -g $< -L. -I. -lft -o $@

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm: $(LIBFT_H) $(SRCS) $(INCS_DIR)
	@norminette $^
