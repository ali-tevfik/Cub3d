GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

SRCS	=	get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			main.c\
			keyboard.c\
			check_position.c\
			draw_ray.c\
			clean_maps.c\
			create_items.c\
			load_maps.c\
			draw3D.c\
			src/check_map_borders.c\
			src/colours.c\
			src/error_handling.c\
			src/exam_gnl.c\
			src/form_data_structure.c\
			src/form_grid.c\
			src/initiate_data.c\
			src/initiate_map_size.c\
			src/map_utils.c\
			src/parsing_gamestate.c\
			src/textures.c\
			distance_ray.c

OBJS	= $(SRCS:.c=.o)

LIBFT_DIR = libft

LIBFT_LIB = libft.a

NAME	= cub3d

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror -g
# FLAGS	= -Wall -Wextra
# #-Werror
# >>>>>>> d70ab1430d72886f6931f085304feb0f281a2489

HEADER_FILE =	cub3d.h\
				includes

MLX_DIR	= minilibx_opengl

MLX_LIB = libmlx.a

LINKS = -framework OpenGL -framework AppKit

all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(GCC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT_LIB) $(MLX_DIR)/$(MLX_LIB) $(LINKS)

%.o: %.c $(HEADER_FILE)
	@echo "$(GREEN)Compiling:$(NORMAL)"
	$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)
	@echo "$(GREEN)Successfully compiled!$(NORMAL)"

run: all 
	./$(NAME) maps_variations/ali_maps.cub
clean:
	@echo "$(RED)Removing all object files...$(NORMAL)"
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Succesfully removed all object files!$(NORMAL)"

fclean: clean
	@echo "$(RED)Removing libraries and bitmap file...$(NORMAL)"
	rm -f $(NAME)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Successfully removed libraries and bitmap file!$(NORMAL)"

re: fclean all

.PHONY:	clean fclean re
