PATH_SRC = ./src/
PATH_GNL = $(PATH_SRC)gnl/
PATH_MAP = $(PATH_SRC)map/
PATH_UTILS = $(PATH_SRC)utils/
PATH_ERRORS = $(PATH_SRC)errors/
PATH_GAME = $(PATH_SRC)game/
PATH_MLX = ./minilibx/
PATH_OBJS = ./objs/

MLX = $(PATH_MLX)libmlx.a
NAME = so_long

FILES = $(PATH_MAP)map.c $(PATH_MAP)check.c $(PATH_MAP)valid_maps.c \
		$(PATH_MAP)render_map.c $(PATH_MAP)init_sprites.c \
		$(PATH_GNL)get_next_line.c $(PATH_GNL)get_next_line_utils.c \
		$(PATH_UTILS)ft_calloc.c $(PATH_UTILS)ft_memset.c $(PATH_UTILS)ft_split.c \
		$(PATH_UTILS)ft_strlen.c $(PATH_UTILS)check_extension.c $(PATH_UTILS)ft_itoa.c\
		$(PATH_ERRORS)errors.c \
		$(PATH_GAME)start.c $(PATH_GAME)action.c $(PATH_GAME)move.c

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(FILES))

CC = clang
CFLAGS = -Wextra -Werror -Wall
MLXFLAGS = -I $(PATH_MLX) -L $(PATH_MLX) -lmlx -Ilmlx -lXext -lX11
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo objects done!!
	@make -C $(PATH_MLX)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(PATH_SRC)so_long.c $(OBJS) $(MLX) -o so_long
	@echo program done!

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)map
	@mkdir -p $(PATH_OBJS)gnl
	@mkdir -p $(PATH_OBJS)utils
	@mkdir -p $(PATH_OBJS)errors
	@mkdir -p $(PATH_OBJS)game
	$(CC) $(CFLAGS) -I. -c $< -o $@

bonus: all

clean:
	$(RM) $(PATH_OBJS)
	@echo obj removed!

fclean: clean
	make clean -C $(PATH_MLX)
	$(RM) $(NAME)
	@echo clean everything

re: fclean all

.PHONY: re all fclean clean

test:	
	$(CC) -fsanitize=leak $(MLXFLAGS) $(CFLAGS) $(PATH_SRC)so_long.c $(FILES) ./minilibx/libmlx.a -o so_long

norminha:
	norminette so_long.h ./src

git:
	git add .
	git commit -m "center image readme"
	git push origin master 
