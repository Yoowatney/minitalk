# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 23:07:54 by yoyoo             #+#    #+#              #
#    Updated: 2021/08/21 21:45:20 by yoyoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          = gcc
SERVER      = server
CLIENT      = client
CFLAG       = -Wall -Wextra -Werror
LIBFT       = libft.a

SRCS		= server.c client.c utils.c

SRCS_DIR    = ./b_part/
B_SRCS      = $(addprefix $(SRCS_DIR), server_bonus.c client_bonus.c utils_bonus.c)

B_SERVER    = server_bonus
B_CLIENT    = client_bonus

.PHONY : all clean fclean re bonus

all : $(LIBFT) $(SERVER) $(CLIENT)
	@rm -f server_bonus.o client_bonus.o

$(LIBFT) :
	@make -C libft

$(SERVER) : server.o utils.o
	@$(CC) $(CFLAG) -o $@ server.o utils.o -l ft -L ./libft
	@printf "\e[93mserver build success💻\n\e[0m"

$(CLIENT) : client.o utils.o
	@$(CC) $(CFLAG) -o $@ client.o utils.o -l ft -L ./libft
	@printf "\e[93mclient build success📱\n\e[0m"

%.o : $(SRCS) $(B_SRCS) # %.c
	@$(CC) $(CFLAG) $(SRCS) $(B_SRCS) -c 

#%.o : $(B_SRCS)
	#@$(CC) $(CFLAG) $(B_SRCS) -c

bonus : $(LIBFT) $(B_SERVER) $(B_CLIENT)
	@printf "\e[93mBonus build success\n\e[0m"

$(B_SERVER) : server_bonus.o utils_bonus.o $(LIBFT)
	@$(CC) $(CFLAG) -o $(B_SERVER) utils_bonus.o server_bonus.o -l ft -L ./libft


$(B_CLIENT) : client_bonus.o utils_bonus.o $(LIBFT)
	@$(CC) $(CFLAG) -o $(B_CLIENT) utils_bonus.o client_bonus.o -l ft -L ./libft

clean :
	@make clean -C libft
	@rm -f server.o client.o utils.o
	@printf "\e[35mexecute clean🥡\n\e[0m"

fclean : clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT) $(B_SERVER) $(B_CLIENT) server_bonus.o client_bonus.o utils_bonus.o
	@printf "\e[35mexecute fclean🚽\n\e[0m"

re : fclean all
