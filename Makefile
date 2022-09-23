NAME = philo

SRC =	philo.c init.c threads.c error.c \

OBJ =	philo.o init.o threads.o error.o \

all : $(NAME)

$(NAME):
	
	@gcc $(SRC) -Wall -Werror -Wextra -lpthread -fsanitize=address -g -o $(NAME)

clean :
 
	@rm -f $(OBJ)
	@echo "🚮🚮🚮"

fclean : clean
	@rm -f $(NAME)
	@echo "🗑️ 🗑️ 🗑️"

re : fclean all