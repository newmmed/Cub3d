NAME = cub3d

HEADER = includes/cub3d.h

SRC = parcing/parcing.c		parcing/array.c		parcing/free.c		parcing/get_next_line.c\
	parcing/libft.c		parcing/libft1.c		parcing/multi_split.c		srcs/main.c\
	srcs/draw_map.c srcs/rays.c 	srcs/keyhook.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)
MLX = "./MLX42/build/libmlx42.a"
LDFLAGS = -O3 -Iinclude -lglfw -L"/Users/hanebaro/.brew/Cellar/glfw/3.4/lib"

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

re: fclean all