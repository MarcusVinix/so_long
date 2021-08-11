
PATH_SRC = ./src/
PATH_GNL = $(PATH_SRC)get_next_line/
PATH_MAP = $(PATH_SRC)map/
PATH_UTILS = $(PATH_SRC)utils/
PATH_ERRORS = $(PATH_SRC)errors/
PATH_GAME = $(PATH_SRC)game/


NAME = so_long

FILES = $(PATH_GNL)get_next_line.c $(PATH_GNL)get_next_line_utils.c \
		$(PATH_MAP)map.c $(PATH_MAP)check.c $(PATH_MAP)valid_maps.c \
		$(PATH_UTILS)ft_calloc.c $(PATH_UTILS)ft_memset.c $(PATH_UTILS)ft_split.c $(PATH_UTILS)ft_strlen.c \
		$(PATH_ERRORS)errors.c \
		$(PATH_GAME)start.c

CC = clang
CFLAGS = -I ./minilibx/ -L ./minilibx/ -lmlx -Ilmlx -lXext -lX11 ./minilibx/libmlx.a
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)

clean:
	$(RM) $(OBJS_PATH)

fclean: clean
	$(RM) $(NAME)

test:	
	$(CC) -fsanitize=leak $(PATH_SRC)so_long.c $(FILES) -o so_long