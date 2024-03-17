SRCS =	main.cpp\
		Bureaucrat.cpp\
		AForm.cpp\
		ShrubberyCreationForm.cpp\
		RobotomyRequestForm.cpp\
		PresidentialPardonForm.cpp\
		
INC		= -I includes -I /usr/include

OBJS	= ${SRCS:.cpp=.o}

NAME 	= Form2

CXX 		= c++

RM 		= rm -f

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 
#CXXFLAGS	+= -g3 -fsanitize=address -fsanitize=undefined -fsanitize=leak -Weffc++

all:		${NAME}

.cpp.o :
			$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

${NAME}:	${OBJS}
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:		
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus