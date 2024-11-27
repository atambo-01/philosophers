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

SOURCES         =	src/main.c \
					src/init_philos.c \
					src/utils.c \
					src/routine.c \
					src/routine_utils.c \
			
CC              = cc
CFLAGS          =  -g -pthread
NAME            = philosophers
OBJS            = $(SOURCES:.c=.o)
INCLUDES        = -Iincludes

SUBDIRS         = ./ft_printf ./libft

LIBS            = ./ft_printf/ft_printf.a ./libft/libft.a

all: submake $(NAME)

submake:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LIBS)

clean:
	rm -f $(OBJS)
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

fclean: clean
	rm -f $(NAME)
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir fclean; \
	done

re: fclean all

.PHONY: all submake clean fclean re

