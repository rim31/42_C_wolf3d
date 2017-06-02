
GC = gcc

FLAG = -I $(INCL) ./minilibx_macos/libmlx.a -framework OpenGl -framework AppKit

SRCS = main.c\
	ft_init.c	ft_map.c	ft_parse.c	ft_start_screen.c	my_key_funct.c \
	mlx_pixel_put_to_image.c ft_small.c ft_move.c ft_ray.c\


LIBFT_PATH = ./libft/

LIBFT_NAME = libft.a

LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

INCL = wolf3d.h

NAME = wolf3d

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@echo "by 😉seng      _  __  _____     _ "
	@echo "\033[89m__      _____ | |/ _| |__ /  __| |"
	@echo "\033[90m\ \ /\ / / _ \| | |_   |_ \ / _  |"
	@echo "\033[91m \ V  V / (_) | |  _| ___) | (_| |"
	@echo "\033[92m  \_/\_/ \___/|_|_|  |____/ \__,_|"

		@echo "\033[92mCompiling"
		@make re -C $(LIBFT_PATH)
		@$(GC) -o $(NAME) -Wall -Wextra -Werror $(SRCS) $(FLAG) $(LIBFT)
		@echo "\033[96m->Done"
		@make fclean -C $(LIBFT_PATH)

clean:
		@echo "\033[92mDeleting"
		@rm -f $(OBJ)
		@make fclean -C $(LIBFT_PATH)
		@echo "\033[96mClean done"


fclean: clean
		@echo "\033[92mDeleting"
		@rm -f $(NAME)
		@make fclean -C $(LIBFT_PATH)
		@echo "\033[96mFclean Done"

re: fclean all

.PHONY: all clean fclean re
