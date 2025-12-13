NAME = Bureaucrats
FLAGS = -Wall -Werror -Wextra -std=c++98
FILES = main \
		Bureaucrat \
		AForm \
		PresidentialPardonForm \
		RobotomyRequestForm \
		ShrubberyCreationForm \


SRC = $(addsuffix .cpp, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ)
	g++ $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	g++ $(FLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
