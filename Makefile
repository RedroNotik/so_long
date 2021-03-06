NAME = so_long

FLAGS =   -I./includes -Imlx #-Wall -Wextra -Werror

LIST = ./src/parsing.c ./src/parsing_check.c  ./src/move_player.c ./src/drawing_map.c  \
		./main.c ./src/key_hooker.c

B_LIST = ./src/parsing.c ./bonus/parsing_check_bonus.c  ./bonus/move_player_bonus.c \
 		./bonus/drawing_map_bonus.c  \
		./bonus/move_bonus.c ./bonus/main_bonus.c ./bonus/key_hooker_bonus.c

OBJ	= $(patsubst %.c,%.o,$(LIST))

B_OBJ = $(patsubst %.c,%.o,$(B_LIST))

all :
	@make -C ./libft/
	@make $(NAME)

$(NAME) : $(OBJ) ./libft/libft.a
	@gcc -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) ./libft/libft.a
	@echo "\033[1;32m[Success]\x1b[0m"

bonus: $(B_OBJ)
	@make -C ./libft/
	@gcc -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(B_OBJ) ./libft/libft.a
	@echo "\033[1;32m[Bonus Success]\x1b[0m"

%.o : %.c
	@gcc $(FLAGS) -c $< -o $@

clean :
	@make clean -C ./libft/
	@rm -f $(OBJ) $(B_OBJ)
	@echo "\033[90m[\033[33mClean\033[90m]\x1b[0m"

fclean : clean
	@make fclean -C ./libft/
	@rm -f $(NAME)
	@echo "\033[90m[\033[31mDelete\033[90m]\x1b[0m"

re : fclean all
	@echo "\033[90m[\033[35mRebuilded\033[90m]\x1b[0m"

.PHONY : all clean fclean re