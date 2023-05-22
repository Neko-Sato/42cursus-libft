
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

LIBFT_H = libft.h

SRCSDIR = ./

SRCS_MANDATORY_PART_1 = \
	$(SRCSDIR)ft_memset.c \
	$(SRCSDIR)ft_bzero.c \
	$(SRCSDIR)ft_memcpy.c \
	$(SRCSDIR)ft_memmove.c \
	$(SRCSDIR)ft_memchr.c \
	$(SRCSDIR)ft_memcmp.c \
	$(SRCSDIR)ft_strlen.c \
	$(SRCSDIR)ft_isalpha.c \
	$(SRCSDIR)ft_isdigit.c \
	$(SRCSDIR)ft_isalnum.c \
	$(SRCSDIR)ft_isascii.c \
	$(SRCSDIR)ft_isprint.c \
	$(SRCSDIR)ft_toupper.c \
	$(SRCSDIR)ft_tolower.c \
	$(SRCSDIR)ft_strchr.c \
	$(SRCSDIR)ft_strrchr.c \
	$(SRCSDIR)ft_strncmp.c \
	$(SRCSDIR)ft_strlcpy.c \
	$(SRCSDIR)ft_strlcat.c \
	$(SRCSDIR)ft_strnstr.c \
	$(SRCSDIR)ft_atoi.c \
	$(SRCSDIR)ft_calloc.c \
	$(SRCSDIR)ft_strdup.c \

SRCS_MANDATORY_PART_2 = \
	$(SRCSDIR)ft_substr.c \
	$(SRCSDIR)ft_strjoin.c \
	$(SRCSDIR)ft_strtrim.c \
	$(SRCSDIR)ft_split.c \
	$(SRCSDIR)ft_itoa.c \
	$(SRCSDIR)ft_strmapi.c \
	$(SRCSDIR)ft_striteri.c \
	$(SRCSDIR)ft_putchar_fd.c \
	$(SRCSDIR)ft_putstr_fd.c \
	$(SRCSDIR)ft_putendl_fd.c \
	$(SRCSDIR)ft_putnbr_fd.c \

SRCS_MANDATORY_PART = \
	$(SRCS_MANDATORY_PART_1) \
	$(SRCS_MANDATORY_PART_2) \

SRCS_BONUS_PART = \
	$(SRCSDIR)ft_lstnew.c \
	$(SRCSDIR)ft_lstadd_front.c \
	$(SRCSDIR)ft_lstsize.c \
	$(SRCSDIR)ft_lstlast.c \
	$(SRCSDIR)ft_lstadd_back.c \
	$(SRCSDIR)ft_lstdelone.c \
	$(SRCSDIR)ft_lstclear.c \
	$(SRCSDIR)ft_lstiter.c \
	$(SRCSDIR)ft_lstmap.c \

SRCS = \
	$(SRCS_MANDATORY_PART) \
	$(SRCS_BONUS_PART) \

OBJECTS_MANDATORY_PART = $(SRCS_MANDATORY_PART:.c=.o)
OBJECTS_BONUS_PART = $(SRCS_BONUS_PART:.c=.o)

OBJECTS = \
	$(OBJECTS_MANDATORY_PART) \
	$(OBJECTS_BONUS_PART) \

.PHONY: all clean fclean re

$(NAME): mandatory

mandatory: $(OBJECTS_MANDATORY_PART)
	$(AR) rc $(NAME) $(OBJECTS_MANDATORY_PART)

bonus: $(OBJECTS_BONUS_PART)
	$(AR) rc $(NAME) $(OBJECTS_BONUS_PART)

%.o: %.c $(LIBFT_H)
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
