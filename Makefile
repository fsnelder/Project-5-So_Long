SRC = main.c get_next_line.c get_next_line_utils.c error.c setcoordinates.c\
	  createmap.c hooks.c convert.c rules.c

OBJ = $(SRC:.c=.o)

SOLONG = so_long

CFLAGS = -Werror -Wall -Wextra

all: $(SOLONG)

LIBFT = -I libft
MLX_INC = -I MLX42/include -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/

$(SOLONG): $(SRC)
	make -C libft
	make -C MLX42
	gcc $(SRC) $(CFLAGS) $(MLX_INC) $(LIBFT)  libft/libft.a MLX42/libmlx42.a -o so_long

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C MLX42
	rm -f $(SOLONG)

re: fclean all

