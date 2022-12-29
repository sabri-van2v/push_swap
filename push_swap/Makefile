SRC = 	push_swap.c fonctions_utils.c stack_error.c lst_utils.c \
		algorithm.c instructions.c little_len.c

SRCS = 	${addprefix srcs/, ${SRC}}

OBJ = 	${addprefix binaries/, ${SRC}}

OBJS = 	${OBJ:%.c=%.o}

NAME = 	push_swap

CC 	= 	cc

RM 	= 	rm -f

CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = Libft/includes/gnl Libft/includes/libc Libft/includes/ptf includes/

HEADER = includes/push_swap.h

binaries/%.o: srcs/%.c ${HEADER}
	make -C Libft
	mkdir -p binaries/
	${CC} ${CFLAGS} -c $< -o $@ ${addprefix -I, ${INCLUDES}}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS} -LLibft -lft

all: ${NAME}

clean:
	 ${RM} -r binaries
	 make clean -C Libft

fclean: clean
	 ${RM} ${NAME}
	 make fclean -C Libft

re: fclean all