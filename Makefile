NAME = so_long

FLAGS =   -I./includes #-Wall -Wextra -Werror

LIST = ./main.c

OBJ	= $(patsubst %.c,%.o,$(LIST))

all :
	@make -C ./libft/
	@make $(NAME)

$(NAME) : $(OBJ) ./libft/libft.a
	@gcc -o $(NAME) $(OBJ) ./libft/libft.a
	@echo "\033[90m[\033[32mSuccess\033[90m]"

%.o : %.c
	@gcc $(FLAGS) -c $< -o $@

clean :
	@make clean -C ./libft/
	@rm -f $(OBJ)
	@echo "\033[90m[\033[33mClean\033[90m]"

fclean : clean
	@make fclean -C ./libft/
	@rm -f $(NAME)
	@echo "\033[90m[\033[31mDelete\033[90m]"

re : fclean all
	@echo "\033[90m[\033[35mRebuilded\033[90m]"

.PHONY : all clean fclean re