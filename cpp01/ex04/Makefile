NAME = sed
FLAGS = -Wall -Werror -Wextra -std=c++98
FILES = main \

SRC = $(addsuffix .cpp, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)
	touch test

$(OBJ): $(SRC)
	c++ $(FLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f test
	rm -f test.replace

re: fclean all
