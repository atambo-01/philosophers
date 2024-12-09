# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atambo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 14:27:56 by atambo            #+#    #+#              #
#    Updated: 2024/11/16 14:27:58 by atambo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


			
CC              = cc
CFLAGS          = -Wall -Wextra -Werror -g -pthread
NAME            = philo
OBJS            = $(SOURCES:.c=.o)
INCLUDES        = -Iincludes

SOURCES         =	src/main.c \
					src/inits.c \
					src/utils.c \
					src/routine.c \
					src/routine_utils.c \
					src/libft.c \
					src/threads.c \
					src/extra.c \
					src/str.c \
					
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LIBS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

#hello

