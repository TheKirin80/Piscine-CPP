SRCS = 	megaphone.cpp

INC		= -I includes -I /usr/include

OBJS	= ${SRCS:.cpp=.o}

NAME 	= megaphone

CXX 		= c++

RM 		= rm -f

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

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

