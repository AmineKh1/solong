NAME = solong
CC = gcc
CFLAGS = -Wall -Wextra -Werror
# -fsanitize=address
SRC =  solong.c drawing.c move_player.c init_function.c parse_map.c utils/ft_putstr_fd.c utils/ft_split.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_strncmp.c utils/ft_substr.c utils/get_next_line.c utils/ft_printf.c utils/ft_putnbr_base_fd.c utils/ft_putnbr_fd.c utils/ft_putchar_fd.c utils/ft_strrchr.c 
OBJ = ${SRC:.c=.o}
RM = rm -rf
MLX = -lmlx -framework OpenGL -framework Appkit
all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${OBJ} ${MLX} -o ${NAME}
%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@
clean:
	@${RM} ${OBJ}

fclean: clean
	@${RM} ${NAME}

re: fclean all
.PHONY: clean all bonus fclean re¡