CC = cc
CFLAGS = -Werror -Wextra -Wall
NAME = push_swap
CHECKER = checker
RM = rm -rf
LIB = ./libft/libft.a

SRC = ./src/assing.c \
      ./src/check_paramters.c \
      ./src/compare.c \
      ./src/get_next_line.c \
      ./src/get_next_line_utils.c \
      ./src/list_utils.c \
      ./src/movement.c \
      ./src/push_swap.c \
      ./src/sort.c \
      ./src/sort_utils.c \
      ./src/utils.c 

SRC_B = ./src/assing.c \
      ./src/check_paramters.c \
      ./src/compare.c \
      ./src/get_next_line.c \
      ./src/get_next_line_utils.c \
      ./src/list_utils.c \
      ./src/movement.c \
      ./src/checker.c \
      ./src/sort.c \
      ./src/sort_utils.c \
      ./src/utils.c 

OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all : $(NAME)
	@echo "Build successful!"

$(NAME) : $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

bonus: $(CHECKER)
	@echo "Build successful!"

$(CHECKER) :  $(OBJ_B) $(LIB)
	$(CC) $(CFLAGS) -o $(CHECKER) $(OBJ_B) $(LIB)

$(LIB) :
	@make -sC ./libft/ all
	@echo "CREATING libft.a LIBRARY : DONE"

clean :
	@echo "Cleaning..."
	@$(RM) $(OBJ) $(OBJ_B)
	@make -sC ./libft/ clean
	@echo "Cleanup complete!"

fclean : clean
	@echo "Full cleanup..."
	@$(RM) $(NAME) $(CHECKER)
	@make -sC ./libft/ fclean
	@echo "Full cleanup complete!"

re : fclean all

