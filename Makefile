# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 21:58:50 by hshimizu          #+#    #+#              #
#    Updated: 2024/05/20 05:49:57 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_OS	:= $(shell uname -s)

NAME		:= libft.a
ifeq ($(UNAME_OS), Darwin)
NAME_SO		:= libft.dylib
else
NAME_SO		:= libft.so
endif
LIBFT_H		:= libft.h
ROOT_DIR	:= .
INCS_DIR	:= $(ROOT_DIR)/incs
OUT_DIR		:= $(ROOT_DIR)/out

SRCS 		:= \
	$(addprefix $(ROOT_DIR)/, \
		$(addprefix ft_array/, \
			ft_2darraydel.c \
			ft_2darraynew.c \
			ft_ndarraydel.c \
			ft_ndarraynew.c \
			ft_average.c \
			ft_issorted.c \
			ft_maxarray.c \
			ft_minarray.c \
			ft_sort.c \
			ft_sum.c \
			ft_all.c \
			ft_any.c \
			ft_arrylen.c \
		) \
		$(addprefix ft_ctype/, \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_isblank.c \
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
			ft_getfilename.c \
		) \
		$(addprefix ft_put_fd/, \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_putstrarry_fd.c \
		) \
		$(addprefix ft_stdlib/, \
			ft_abs.c \
			ft_atof.c \
			ft_strtol.c \
			ft_strtold.c \
			ft_strtod.c \
			ft_atoi.c \
			ft_atol.c \
			ft_calloc.c \
			ft_itoa.c \
			ft_utoa.c \
			ft_qsort.c \
			ft_random.c \
			ft_mktemp.c \
			ft_mkstemp.c \
			ft_realpath.c \
		) \
		$(addprefix ft_strgen/, \
			ft_strgennew.c \
			ft_strgendel.c \
			ft_strgencomp.c \
			ft_strgenflush.c \
			ft_strgenchr.c \
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
			ft_strstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_strndup.c \
			ft_strcpy.c \
			ft_strspn.c \
			ft_strcspn.c \
			ft_strpbrk.c \
			ft_strtok.c \
			ft_strtok_r.c \
			ft_strsep.c \
			ft_strcasecmp.c \
			ft_strncasecmp.c \
			ft_memfrob.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strncpy.c \
			ft_strset.c \
			ft_strnset.c \
		) \
		$(addprefix ft_utils/, \
			ft_digit.c \
			ft_isnumber.c \
			ft_max.c \
			ft_min.c \
			ft_sign.c \
			ft_gcd.c \
			ft_lcm.c \
			ft_isprime.c \
			ft_intcmp.c \
			ft_intptrcmp.c \
			ft_strptrcmp.c \
			ft_noop.c \
			ft_ctoi.c \
			ft_sortstrarry.c \
			ft_strarrydup.c \
			ft_startwith.c \
			ft_endwith.c \
			ft_deg2rad.c \
			ft_rad2deg.c \
			ft_shlex.c \
		) \
		$(addprefix ft_xlst/, \
			ft_xlstlen.c \
			ft_xlstat.c \
			ft_xlstset.c \
			ft_xlstget.c \
			ft_xlstappend.c \
			ft_xlstinsert.c \
			ft_xlstpop.c \
			ft_xlstdel.c \
			ft_xlstclear.c \
			ft_xlst2array.c \
			ft_xlstappendarry.c \
			ft_xlst_find.c \
		) \
		$(addprefix ft_operator/, \
			ft_eq.c \
			ft_ge.c \
			ft_gt.c \
			ft_le.c \
			ft_lt.c \
			ft_mod.c \
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
		$(addprefix ft_vector/, \
			ft_vector.c \
			ft_vector_new.c \
			ft_vector_del.c \
			ft_vector_sizeoftype.c \
			ft_vector_capacity.c \
			ft_vector_size.c \
			ft_vector_reserve.c \
			ft_vector_resize.c \
			ft_vector_shrink_to_fit.c \
			ft_vector_growth.c \
			ft_vector_clear.c \
			ft_vector_erase.c \
			ft_vector_insert.c \
			ft_vector_pop_back.c \
			ft_vector_push_back.c \
		)\
		$(addprefix ft_search/, \
			__getnodep.c \
			__minnodep.c \
			ft_tsearch.c \
			ft_tfind.c \
			ft_twalk.c \
			ft_twalk_r.c \
			ft_tdelete.c \
			ft_tdestroy.c \
			ft_lsearch.c \
			ft_lfind.c \
		)\
		$(addprefix ft_bufferio/, \
			ft_bufferio_read.c \
			ft_bufferio_resize.c \
			ft_open.c \
			ft_close.c \
			ft_read.c \
			ft_write.c \
			ft_readline.c \
		) \
		$(addprefix ft_color/, \
			ft_rgba.c \
			ft_hsvt.c \
			ft_color_add.c \
			ft_color_sub.c \
			ft_color_mul.c \
		) \
		$(addprefix ft_interval/, \
			ft_interval.c \
			ft_intervalf.c \
		) \
	)

OBJS		:= $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS		:= $(addprefix $(OUT_DIR)/, $(SRCS:.c=.d))

CFLAGS		:= -Wall -Wextra -Werror
ifeq ($(DEBUG), 1)
CFLAGS		+= -g
else
CFLAGS		+= -O2
endif
IDFLAGS		:= -I$(INCS_DIR)

.PHONY: all clean fclean re bonus norm test

all: $(NAME) $(NAME_SO)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(AR) rc $@ $^

$(NAME_SO): $(OBJS)
	$(CC) -shared -fPIC $^ -o $@

$(OUT_DIR)/%.o: %.c $(LIBFT_H)
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) -MMD -MP $(IDFLAGS) $< -o $@

clean:
	$(RM) -r $(OUT_DIR)

fclean: clean
	$(RM) $(NAME) $(NAME_SO)

re: fclean all

norm: $(LIBFT_H) $(INCS_DIR) $(SRCS)
	@norminette $^

test: test.c $(SRCS)
	$(CC) -g  $^ -o $@ -I$(INCS_DIR) -lm

-include $(DEPS)
