NAME = test

SRC = src/*.c

LIBFT = libft
INC = includes

LIBS = -L$(LIBFT) -lft
HEADERS = -I$(INC) -I$(LIBFT)
FLAGS = -Wall -Werror -Wextra $(LIBS) $(HEADERS)

all:
	make -s -C $(LIBFT)
	gcc $(SRC) $(FLAGS) -o $(NAME)

clean:
	make fclean -s -C $(LIBFT)
	rm -f $(NAME)

fclean: clean

re: clean all