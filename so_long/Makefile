NAME= so_long
LIBFT= libft/libft.a
CC= cc
CFLAGS= -Wall -Wextra -Werror 
FILE= workshop.c	\
	outils_check.c	\
	outils2_check.c	\
	outils3_check.c	\
	intialisation.c	\
	put_map.c	\

FILEO= $(FILE:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(FILEO) $(LIBFT)
	$(CC) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(FILEO) $(LIBFT) -o $(NAME)

$(LIBFT):
	make all -C ./libft

clean:
	rm -rf $(FILEO)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all