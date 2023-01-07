SRC = 	main.c stack_error.c presorting.c little_len.c \
		create_stack_a.c delete.c incrementation.c sort_tab.c \
		lst_utils.c fonctions_utils.c sorting_algorithm.c path.c \
		push.c rotate.c swap.c reverse_rotate.c debug.c

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