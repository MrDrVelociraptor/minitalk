SRVR = src/server.c
CLNT = src/client.c

LIBFT = libft
INC = includes

LIBS = -L$(LIBFT) -lft
HEADERS = -I$(INC) -I$(LIBFT)
FLAGS = -Wall -Werror -Wextra $(LIBS) $(HEADERS)

all:
	@make -s -C $(LIBFT)
	@echo Compiling libft
	@gcc $(SRVR) $(FLAGS) -o server
	@echo Compiling server
	@gcc $(CLNT) $(FLAGS) -o client
	@echo Compiling client
	@echo Good to go
	

clean:
	@make fclean -s -C $(LIBFT)
	@rm -f client server
	@echo nothing here anymore, well, except .c

fclean: clean

re: clean all