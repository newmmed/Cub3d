NAME = miniRT
NAME_BONUS = fdf_bonus

HEADER = mandatory/minirt.h
#HEADER_BONUS = includes/fdf_bonus.h
SRC =	mandatory/libft.c	mandatory/split.c	mandatory/get_next_line.c	\
		mandatory/multi_split.c	mandatory/parcing_help.c	mandatory/parcing.c	mandatory/scene_funct.c\
		mandatory/scene_funct1.c		mandatory/scene.c	mandatory/help_scene.c	\
		mandatory/A.c	mandatory/C.c		mandatory/L.c	mandatory/pl.c	mandatory/sp.c	mandatory/cy.c	\
# mandatory/main.c 

# SRCB = bonus/main_bonus.c bonus/draw_points_bonus.c   bonus/get_next_line_bonus.c bonus/input_utils2_bonus.c   \
# 		bonus/split_bonus.c bonus/iso_bonus.c    bonus/moves2_bonus.c \
# 		bonus/free_bonus.c   bonus/input_bonus.c  bonus/input_utils_bonus.c   bonus/libft_bonus.c   \
# 		bonus/map_bonus.c    bonus/moves_bonus.c  bonus/split_utils_bonus.c


CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
MLX = "./MLX42/build/libmlx42.a"
LDFLAGS = -O3 -Iinclude -lglfw -L"/Users/hanebaro/.brew/Cellar/glfw/3.4/lib"
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LDFLAGS) $(FRAMEWORKS) -o $(NAME) 

bonus: $(OBJB) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(OBJB) $(MLX) $(LDFLAGS) $(FRAMEWORKS) -o $(NAME_BONUS) 

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all