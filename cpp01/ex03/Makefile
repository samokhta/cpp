NAME = violence
FLAGS = -Wall -Werror -Wextra -std=c++98
FILES = main \
		HumanA \
		HumanB \
		Weapon \

SRC = $(addsuffix .cpp, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	c++ $(FLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
