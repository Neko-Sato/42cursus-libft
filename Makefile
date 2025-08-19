# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 19:05:06 by hshimizu          #+#    #+#              #
#    Updated: 2025/08/19 20:46:26 by hshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S			:= $(shell uname -s)

NAME 			:= libft
NAME_DEV 		:= $(NAME)_dev

NAME_A			:= $(NAME).a
NAME_DEV_A		:= $(NAME_DEV).a
ifeq ($(UNAME_S),Linux)
NAME_SO			:= $(NAME).so
NAME_DEV_SO		:= $(NAME_DEV).so
else ifeq ($(UNAME_S),Darwin)
NAME_SO			:= $(NAME).dylib
NAME_DEV_SO		:= $(NAME_DEV).dylib
else
$(error Unsupported OS: $(UNAME_S))
endif

SRCS			:= \
	$(addprefix ft_ctype/, \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isblank.c \
		ft_iscntrl.c \
		ft_isdigit.c \
		ft_isgraph.c \
		ft_islower.c \
		ft_isprint.c \
		ft_ispunct.c \
		ft_isspace.c \
		ft_isupper.c \
		ft_isxdigit.c \
		ft_tolower.c \
		ft_toupper.c \
	) \
	$(addprefix ft_string/, \
		ft_bzero.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdup.c \
		ft_memfrob.c \
		ft_memmem.c \
		ft_memmove.c \
		ft_memset.c \
		ft_memswap.c \
		ft_split.c \
		ft_strcasecmp.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strcspn.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncasecmp.c \
		ft_strncat.c \
		ft_strnchr.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnlen.c \
		ft_strnset.c \
		ft_strnstr.c \
		ft_strpbrk.c \
		ft_strrchr.c \
		ft_strsep.c \
		ft_strset.c \
		ft_strspn.c \
		ft_strstr.c \
		ft_strtok.c \
		ft_strtok_r.c \
		ft_strtrim.c \
		ft_substr.c \
	) \
	$(addprefix ft_put_fd/, \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putstrs_fd.c \
	) \
	$(addprefix ft_stdlib/, \
		ft_abs.c \
		ft_atof.c \
		ft_atoi.c \
		ft_atol.c \
		ft_bsearch.c \
		ft_calloc.c \
		ft_div.c \
		ft_itoa.c \
		ft_labs.c \
		ft_ldiv.c \
		ft_qsort.c \
		ft_qsort_r.c \
		ft_strtod.c \
		ft_strtof.c \
		ft_strtol.c \
		ft_strtoul.c \
		ft_strtold.c \
	) \
	$(addprefix ft_list/, \
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
	$(addprefix ft_utils/, \
		ft_startwith.c \
		ft_endwith.c \
		ft_intcmp.c \
		ft_strptrcmp.c \
		ft_digitval.c \
		ft_skip_whitespace.c \
	) \
	$(addprefix ft_vector/, \
		ft_vector_data.c \
		ft_vector_destroy.c \
		ft_vector_init.c \
		ft_vector_resize.c \
		ft_vector_size.c \
	) \
	$(addprefix ft_deque/, \
		ft_deque_at.c \
		ft_deque_destroy.c \
		ft_deque_expand_back.c \
		ft_deque_expand_front.c \
		ft_deque_init.c \
		ft_deque_shrink_back.c \
		ft_deque_shrink_front.c \
		ft_deque_size.c \
	) \
	$(addprefix ft_slist/, \
		ft_slist_destroy.c \
		ft_slist_erase.c \
		ft_slist_head.c \
		ft_slist_init.c \
		ft_slist_insert.c \
		ft_slist_node_delete.c \
		ft_slist_node_new.c \
		ft_slist_node_next.c \
		ft_slist_size.c \
	) \
	$(addprefix ft_dlist/, \
		ft_dlist_destroy.c \
		ft_dlist_erase.c \
		ft_dlist_head.c \
		ft_dlist_init.c \
		ft_dlist_insert.c \
		ft_dlist_node_delete.c \
		ft_dlist_node_new.c \
		ft_dlist_size.c \
		ft_dlist_tail.c \
	) \
	$(addprefix ft_btree/, \
		ft_btree_destroy.c \
		ft_btree_find.c \
		ft_btree_head.c \
		ft_btree_init.c \
		ft_btree_lower_bound.c \
		ft_btree_node_delete.c \
		ft_btree_node_new.c \
		ft_btree_node_next.c \
		ft_btree_upper_bound.c \
	)

OUTDIR			:= .out
OBJS			:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.o))
OBJS_DEV		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=_dev.o))
DEPS			:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.d))
DEPS_DEV		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=_dev.d))

CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -std=c99 -pedantic
CFLAGS			+= -fno-builtin -fno-common
CFLAGS			+= -fPIC -MMD -MP
AR				:= ar
ARFLAGS			:= rcs
IDFLAGS			:= -I.
LDFLAGS			:=
LIBS			:=
LIBS_DEV		:=

CFLAGS_OPT		:= -O3 -DNDEBUG
CFLAGS_DEV		:= -g -fsanitize=address
ifneq ($(shell $(CC) --version | grep -i clang),)
CFLAGS_DEV		+= -fstandalone-debug
endif

.PHONY: all clean fclean re bonus

all:
	@$(MAKE) $(NAME_A) -j $(shell nproc)

bonus: all

$(NAME_A): CFLAGS += $(CFLAGS_OPT)
$(NAME_A): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(NAME_SO): CFLAGS += $(CFLAGS_OPT)
$(NAME_SO): $(OBJS)
ifeq ($(UNAME_S),Linux)
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -o $@ $^ $(LIBS)
else ifeq ($(UNAME_S),Darwin)
	$(CC) $(CFLAGS) $(LDFLAGS) -dynamiclib -o $@ $^ $(LIBS) -install_name @rpath/$@
endif

$(OUTDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IDFLAGS) -c $< -o $@

$(NAME_DEV_A): CFLAGS += $(CFLAGS_DEV)
$(NAME_DEV_A): $(OBJS_DEV)
	$(AR) $(ARFLAGS) $@ $^

$(NAME_DEV_SO): CFLAGS += $(CFLAGS_DEV)
$(NAME_DEV_SO): $(OBJS_DEV)
ifeq ($(UNAME_S),Linux)
	$(CC) $(CFLAGS) $(LDFLAGS) -shared -o $@ $^ $(LIBS_DEV)
else ifeq ($(UNAME_S),Darwin)
	$(CC) $(CFLAGS) $(LDFLAGS) -dynamiclib -o $@ $^ $(LIBS_DEV) -install_name @rpath/$@
endif

$(OUTDIR)/%_dev.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IDFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OUTDIR)

fclean: clean
	$(RM) $(NAME_A) $(NAME_SO) $(NAME_DEV_A) $(NAME_DEV_SO)

re:
	@$(MAKE) fclean
	@$(MAKE)

test: test.c $(NAME_DEV_A)
	$(CC) $(CFLAGS_DEV) -o $@ $< -I. -L. -lft_dev

-include $(DEPS) $(DEPS_DEV)
