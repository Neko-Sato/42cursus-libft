# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hshimizu <hshimizu@42tokyo.student.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 19:05:06 by hshimizu          #+#    #+#              #
#    Updated: 2025/08/19 19:14:24 by hshimizu         ###   ########.fr        #
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
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c

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
IDFLAGS			:=
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

test: test.c
	$(MAKE) $(NAME_DEV_A) -j $(shell nproc)
	$(CC) $(CFLAGS_DEV) -o $@ $< -I. -L. -lft_dev

-include $(DEPS) $(DEPS_DEV)
