NAME = megaphone
FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(NAME).o
	g++ $(FLAGS) $(NAME).o -o $(NAME)

$(NAME).o: $(NAME).cpp
	g++ $(FLAGS) -c $(NAME).cpp

clean:
	rm -f $(NAME).o

fclean: clean
	rm -f $(NAME)

re: fclean all