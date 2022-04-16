CC = gcc
CFLAGS = -Wall -Werror -Wextra
CLIENT = $(CC) $(CFLAGS) client.c mini_talk_utils.c -o $(NAME_CL)
SERVER = $(CC) $(CFLAGS) server.c mini_talk_utils.c -o $(NAME_SV)
NAME_CL = client
NAME_SV = server

all: $(NAME_CL) $(NAME_SV)
$(NAME_CL):
	$(CLIENT)
$(NAME_SV):
	$(SERVER)
clean:
	rm -rf client server
norm:
	norminette *.c *.h
run:
	@make
	./server
fclean: clean
re: clean all
.PHONY: all clean fclean re