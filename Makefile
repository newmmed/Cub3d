NAME = cub3d

HEADER = includes/cub3d.h

SRC = parcing/parcing.c		parcing/array.c		parcing/free.c		parcing/get_next_line.c\
	parcing/libft.c		parcing/libft1.c		parcing/multi_split.c		srcs/main.c\
	srcs/draw_map.c srcs/rays.c 	srcs/keyhook.c srcs/textures.c\

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)
MLX = "/home/mjadid/MLX42/build/libmlx42.a"
LDFLAGS = -Iinclude -Lbuild  -lglfw -ldl -lm -lpthread

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
		$(CC) $(OBJ) $(MLX) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADER)
		$(CC)  -Iincludes -c $< -o $@

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)

re: fclean all