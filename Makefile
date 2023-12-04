SRCS = $(addprefix Sources/, main.c Utils/ft_putstr_fd.c Utils/ft_strlen.c Utils/gnl/get_next_line.c Utils/gnl/get_next_line_utils.c Checker/arg_checker.c Checker/map_checker.c Checker/map_checker2.c)

NAME = cub3d

INC = -I ./

FLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

${NAME} : ${OBJS}
			gcc ${FLAGS} ${INC} $(OBJS) -o $(NAME)

all : ${NAME}

%.o:%.c
		gcc ${FLAGS} -c $< -o $@

clean :
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re NAME
