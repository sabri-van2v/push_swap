SRC = 	main.c stack_error.c presorting.c little_len.c \
		create_stack_a.c delete.c incrementation.c sort_tab.c \
		lst_utils.c fonctions_utils.c sorting_algorithm.c path.c \
		push.c rotate.c swap.c reverse_rotate.c

SRC_BONUS =	main_bonus.c stack_error_bonus.c \
			create_stack_a_bonus.c delete_bonus.c \
			lst_utils_bonus.c fonctions_utils_bonus.c \
			push_bonus.c rotate_bonus.c \
			swap_bonus.c reverse_rotate_bonus.c

SRCS = 	${addprefix srcs/, ${SRC}}

SRCS_BONUS = ${addprefix bonus/, ${SRC_BONUS}}

OBJ = 	${addprefix binaries/, ${SRC}}

OBJS = 	${OBJ:%.c=%.o}

OBJ_BONUS =	${addprefix binaries/, ${SRC_BONUS}}

OBJS_BONUS = ${OBJ_BONUS:%.c=%.o}

NAME = 	push_swap

NAME_BONUS = checker

MAKELIB = @make -C Libft

MAKEBIN = @mkdir -p binaries/

MAKEFLAGS += --no-print-directory 

CC 	= 	cc

RM 	= 	rm -f

CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = Libft/includes/gnl Libft/includes/libc Libft/includes/ptf includes/

HEADER = includes/push_swap.h

HEADER_BONUS = includes/push_swap_bonus.h

binaries/%.o: srcs/%.c ${HEADER} Libft/libft.a | binaries
	${CC} ${CFLAGS} -c $< -o $@ ${addprefix -I, ${INCLUDES}}

binaries/%.o: bonus/%.c ${HEADER_BONUS} Libft/libft.a | binaries
	${MAKEBIN}
	${CC} ${CFLAGS} -c $< -o $@ ${addprefix -I, ${INCLUDES}}

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS} -LLibft -lft

${NAME_BONUS}: ${OBJS_BONUS}
	${CC} -o ${NAME_BONUS} ${OBJS_BONUS} -LLibft -lft

all: ${NAME}

Libft/libft.a:
	${MAKELIB}

binaries:
	${MAKEBIN}

bonus: ${NAME_BONUS}

clean:
	 ${RM} -r binaries
	 make clean -C Libft

fclean: clean
	 ${RM} ${NAME} ${NAME_BONUS}
	 make fclean -C Libft

re: fclean all

.PHONY:	all bonus clean fclean re
