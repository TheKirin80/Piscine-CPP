SRCS = Contact.cpp PhoneBook.cpp main.cpp

INC		= -I includes -I /usr/include

OBJS	= ${SRCS:.cpp=.o}

NAME 	= PhoneBook

CC 		= c++

RM 		= rm -f

CFLAGS	= -Wall -Wextra -Werror -std=c++98

all:		${NAME}

.cpp.o :
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

${NAME}:	${OBJS}
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:		
			${RM} ${OBJS} 

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus

