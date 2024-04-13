CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libft.a
AR = ar rcs

SRC = ft_memset.c \
      ft_strlen.c \
      ft_putchar_fd.c \
      ft_strmapi.c \
      ft_bzero.c \
      ft_putendl_fd.c \
      ft_strncmp.c \
      ft_calloc.c \
      ft_putnbr_fd.c \
      ft_strnstr.c \
      ft_putstr_fd.c \
      ft_isalnum.c \
      ft_atoi.c \
      ft_toupper.c \
      ft_strrchr.c \
      ft_split.c \
      ft_strtrim.c \
      ft_isalpha.c \
      ft_strchr.c \
      ft_substr.c \
      ft_isascii.c \
      ft_strdup.c \
      ft_tolower.c \
      ft_isdigit.c \
      ft_memchr.c \
      ft_striteri.c \
      ft_isprint.c \
      ft_memcmp.c \
      ft_strjoin.c \
      ft_itoa.c \
      ft_memcpy.c \
      ft_strlcat.c \
      ft_memmove.c \
      ft_strlcpy.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
