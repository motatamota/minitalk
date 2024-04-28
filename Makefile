CC = cc
CFLAGS = -Wall -Wextra -Werror
INCDIR = includes
SSRC = server_src/byte.c server_src/main.c server_src/main2.c
CSRC = client_src/main.c
SOBJ = $(SSRC:%.c=%.o)
COBJ = $(CSRC:%.c=%.o)
CLIENT = client
SERVER = server
PLIBA = printf/libftprintf.a

all: $(CLIENT) $(SERVER)

$(CLIENT): $(COBJ) $(PLIBA)
	$(CC) $(CFLAGS) $(COBJ) $(PLIBA) -o $(CLIENT)

$(SERVER): $(SOBJ)
	$(CC) $(CFLAGS) $(SOBJ) $(PLIBA) -o $(SERVER)

$(PLIBA):
	make -C printf

bonus: $(CLIENT) $(SERVER)
	touch bonus

server_src/%.o: server_src/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

client_src/%.o: client_src/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(COBJ) $(SOBJ) bonus
	make -C printf fclean

fclean: clean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re
