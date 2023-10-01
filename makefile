NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SUB = ft_atoi.c    main.c utils01.c  utils02.c philo_actions.c ft_putnbr.c ft_calloc.c philo.c
	

OBJ = ${SUB:.c=.o}


all : $(NAME)



$(NAME) :$(OBJ)
	$(CC) ${CFLAGS} ${SUB} -o ${NAME}

clean :
	rm -f $(OBJ)  

fclean : clean
	rm -f $(NAME)  

re : fclean all
