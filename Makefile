SRCS = $(addprefix Srcs/, main.c utils.c mandelbrot.c checker.c julia.c utils2.c)

NAME = fractol

INC = -I ./

FLAGS = -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

${NAME} : ${OBJS}
			gcc ${FLAGS} ${INC} $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all : ${NAME}

%.o:%.c
		gcc ${FLAGS} -Imlx -c $< -o $@

clean :
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re NAME
