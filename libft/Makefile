
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRCDIR = ./

LIBFT_H = $(SRCDIR)libft.h

SRCS_MANDATORY_PART_1 = \
	$(SRCDIR)ft_memset.c \
	$(SRCDIR)ft_bzero.c \
	$(SRCDIR)ft_memcpy.c \
	$(SRCDIR)ft_memmove.c \
	$(SRCDIR)ft_memchr.c \
	$(SRCDIR)ft_memcmp.c \
	$(SRCDIR)ft_strlen.c \
	$(SRCDIR)ft_isalpha.c \
	$(SRCDIR)ft_isdigit.c \
	$(SRCDIR)ft_isalnum.c \
	$(SRCDIR)ft_isascii.c \
	$(SRCDIR)ft_isprint.c \
	$(SRCDIR)ft_toupper.c \
	$(SRCDIR)ft_tolower.c \
	$(SRCDIR)ft_strchr.c \
	$(SRCDIR)ft_strrchr.c \
	$(SRCDIR)ft_strncmp.c \
	$(SRCDIR)ft_strlcpy.c \
	$(SRCDIR)ft_strlcat.c \
	$(SRCDIR)ft_strnstr.c \
	$(SRCDIR)ft_atoi.c \
	$(SRCDIR)ft_calloc.c \
	$(SRCDIR)ft_strdup.c \

SRCS_MANDATORY_PART_2 = \
	$(SRCDIR)ft_substr.c \
	$(SRCDIR)ft_strjoin.c \
	$(SRCDIR)ft_strtrim.c \
	$(SRCDIR)ft_split.c \
	$(SRCDIR)ft_itoa.c \
	$(SRCDIR)ft_strmapi.c \
	$(SRCDIR)ft_striteri.c \
	$(SRCDIR)ft_putchar_fd.c \
	$(SRCDIR)ft_putstr_fd.c \
	$(SRCDIR)ft_putendl_fd.c \
	$(SRCDIR)ft_putnbr_fd.c \

SRCS = \
	$(SRCS_MANDATORY_PART_1) \
	$(SRCS_MANDATORY_PART_2) \

OBJECTS = $(SRCS:.c=.o)

SRCS_BONUS_PART = \
	$(SRCDIR)ft_lstnew.c \
	$(SRCDIR)ft_lstadd_front.c \
	$(SRCDIR)ft_lstsize.c \
	$(SRCDIR)ft_lstlast.c \
	$(SRCDIR)ft_lstadd_back.c \
	$(SRCDIR)ft_lstdelone.c \
	$(SRCDIR)ft_lstclear.c \
	$(SRCDIR)ft_lstiter.c \
	$(SRCDIR)ft_lstmap.c \

OBJECTS_BONUS = $(SRCS_BONUS_PART:.c=.o)

$(NAME): $(OBJECTS)
	$(AR) rc $(NAME) $(OBJECTS)	

bonus:	$(OBJSBONUS)
	$(AR) rc $(NAME) $(OBJECTS_BONUS)

%.o: %.c $(LIBFT_H)
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME) bonus

clean:
	$(RM) -f $(OBJECTS)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
