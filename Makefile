NAME = fillit
SRC = validation.c functionsforvalid.c errors.c forfigures.c algorithm.c mapfunctions.c main.c
INC = fillit.h
LIB = ./libft/

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIB)
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -I$(INC) ./libft/libft.a -I$(LIB)

clean:
	@$(MAKE) -C $(LIB) clean

fclean: clean
	@$(MAKE) -C $(LIB) fclean
	/bin/rm -f $(NAME)

re: fclean all