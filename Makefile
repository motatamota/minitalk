CC = cc
CFLAGS = -Wall -Wextra -Werror
INCDIR = includes
SSRC = $(wildcard server_src/*.c)
CSRC = $(wildcard client_src/*.c)
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

$(PLIBA)
	make -C printf

bonus: all
	touch bounus

server_src/%.o: server_src/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

client_src/%.o: client_src/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(COBJ) $(SOBJ) bonus
	make -C printf clean

fclean: clean
	rm -f client server
	make -C printf fclean

re: fclean all

.PHONY: all clean fclean re
