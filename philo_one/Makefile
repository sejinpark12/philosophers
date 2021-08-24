# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 14:58:35 by sejpark           #+#    #+#              #
#    Updated: 2021/08/24 16:33:48 by sejpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#CC				= gcc
CC				= gcc -g -fsanitize=address
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
NAME			= philo_one

SRC_DIR			= srcs
SRC				= srcs/main.c srcs/philosopher.c srcs/philo_action.c \
				  srcs/observer.c srcs/utils.c \
				  srcs/thread_manager1.c srcs/thread_manager2.c \
				  srcs/ft_atoi.c srcs/ft_strlen.c

OBJ_DIR			= objs
OBJ				= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all :			$(NAME)

$(NAME) :		$(OBJ)
				$(CC) $(CFLAGS) -o $@ $(OBJ)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
				mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) -c $< -o $(<:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

clean :
				$(RM) $(OBJ) $(OBJ_DIR)

fclean :		clean
				$(RM) $(NAME)

re :			fclean all
			
.PHONY :		all clean fclean
