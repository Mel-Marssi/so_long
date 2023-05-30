NAME= so_long
NAMEBONUS=so_long_bonus
LIBFT= libft/libft.a
CC= cc
CFLAGS= -Wall -Wextra -Werror
FILE= workshop.c	\
	outils_check.c	\
	outils2_check.c	\
	outils3_check.c	\
	outils4_check.c	\
	intialisation.c	\
	put_map.c	\
	moves.c	\

BONUS= bonus/workshop_bonus.c	\
	bonus/outils_check_bonus.c	\
	bonus/outils2_check_bonus.c	\
	bonus/outils3_check_bonus.c	\
	bonus/outils4_check_bonus.c	\
	bonus/intialisation_bonus.c	\
	bonus/put_map_bonus.c	\
	bonus/moves_bonus.c	\

FILEO= $(FILE:.c=.o)
BONUSO=$(BONUS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(FILEO) $(LIBFT)
	$(CC) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(FILEO) $(LIBFT) -o $(NAME)

$(LIBFT):
	make all -C ./libft
bonus: $(NAMEBONUS)

$(NAMEBONUS): $(BONUSO)
	$(CC) -lmlx -framework OpenGL -framework AppKit $(CFLAGS) $(BONUSO) $(LIBFT) -o $(NAMEBONUS)

clean:
	rm -rf $(FILEO) $(BONUSO)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME) $(NAMEBONUS)
	make fclean -C ./libft

re: fclean all