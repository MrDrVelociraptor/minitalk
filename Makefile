NAME = test

SRVR = src/server.c
CLNT = src/client.c

LIBFT = libft
INC = includes

LIBS = -L$(LIBFT) -lft
HEADERS = -I$(INC) -I$(LIBFT)
FLAGS = -Wall -Werror -Wextra $(LIBS) $(HEADERS)

all:
	make -s -C $(LIBFT)
	gcc $(SRVR) $(FLAGS) -o server
	gcc $(CLNT) $(FLAGS) -o client

clean:
	make fclean -s -C $(LIBFT)
	rm -f client server

fclean: clean

re: clean all