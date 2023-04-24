SRCS = server.c client.c

SRCS_BONUS = server_bonus.c client_bonus.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = client server

${NAME}:	${OBJS}
	make -C libft all
	$(CC) $(CFLAGS) ./libft/libft.a server.o -o server
	$(CC) $(CFLAGS) ./libft/libft.a client.o -o client

all:	${NAME}

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean:	clean
	rm -f $(NAME)
	make -C libft fclean

re:	fclean all

bonus:	${OBJS_BONUS}
	make -C libft all
	$(CC) $(CFLAGS) libft/libft.a server_bonus.o -o server
	$(CC) $(CFLAGS) libft/libft.a client_bonus.o -o client

.PHONY: all clean fclean re