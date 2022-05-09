PATH_SRC =			./src/
PATH_GNL =			$(PATH_SRC)gnl/
PATH_MAP =			$(PATH_SRC)map/
PATH_UTILS =		$(PATH_SRC)utils/
PATH_ERRORS =		$(PATH_SRC)errors/
PATH_GAME =			$(PATH_SRC)game/
PATH_MLX =			./mlx/
PATH_OBJS =			./objs/

MLX = $(PATH_MLX)libmlx.a
NAME = so_long


FILES = $(PATH_MAP)map.c			$(PATH_MAP)check.c	\
		$(PATH_GNL)get_next_line.c	$(PATH_GNL)get_next_line_utils.c	\
		$(PATH_UTILS)ft_calloc.c	$(PATH_UTILS)ft_bzero.c		$(PATH_UTILS)ft_memset.c		$(PATH_UTILS)ft_split.c	\
		$(PATH_UTILS)ft_strlen.c	$(PATH_UTILS)ft_strdup.c	$(PATH_UTILS)check_extension.c	$(PATH_UTILS)ft_itoa.c	\
		$(PATH_ERRORS)error.c	\
		$(PATH_GAME)window.c		$(PATH_GAME)event.c			$(PATH_GAME)move.c				$(PATH_GAME)print.c		\

OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(FILES))

CC = clang
CFLAGS = -Wextra -Werror -Wall
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo objects done!!
	@$(MAKE) -C $(PATH_MLX)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(PATH_SRC)so_long.c $(OBJS) $(MLX) -o $(NAME)
	@echo program done!

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)map
	@mkdir -p $(PATH_OBJS)gnl
	@mkdir -p $(PATH_OBJS)utils
	@mkdir -p $(PATH_OBJS)errors
	@mkdir -p $(PATH_OBJS)game
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(PATH_OBJS)
	@echo obj removed!

fclean: clean
	make clean -C $(PATH_MLX)
	$(RM) $(NAME)
	@echo clean everything

re: fclean all

.PHONY: re all fclean clean