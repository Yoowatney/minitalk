# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoyoo <yoyoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/18 23:07:54 by yoyoo             #+#    #+#              #
#    Updated: 2021/08/24 23:50:11 by yoyoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LIBFT			= libft.a


SRCS_DIR		= ./mandatory
SRCS			= $(addprefix $(SRCS_DIR)/, server.c client.c utils.c)
OBJS_DIR		= ./obj
OBJS			= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))
SERVER			= server
CLIENT			= client


B_SRCS_DIR		= ./bonus
B_SRCS			= $(addprefix $(B_SRCS_DIR)/, server_bonus.c client_bonus.c utils_bonus.c)
B_OBJS			= $(addprefix $(OBJS_DIR)/, $(notdir $(B_SRCS:.c=.o)))
B_SERVER		= server_bonus
B_CLIENT		= client_bonus


# mandatory
all				: $(LIBFT) $(OBJS_DIR) $(SERVER) $(CLIENT) $(SRCS_DIR)/minitalk.h
	@rm -f server_bonus.o client_bonus.o

$(OBJS_DIR)     :
	@mkdir $(OBJS_DIR)

vpath %.c $(SRCS_DIR)

$(LIBFT)        :
	@make -C libft

$(OBJS_DIR)/%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(SERVER)       : $(OBJS_DIR)/server.o $(OBJS_DIR)/utils.o
	@$(CC) $(CFLAGS) -o $@ $(OBJS_DIR)/server.o $(OBJS_DIR)/utils.o -l ft -L ./libft
	@printf "   \033[0;32m[server build success💻]\n\e[0m"

$(CLIENT)       : $(OBJS_DIR)/client.o $(OBJS_DIR)/utils.o
	@$(CC) $(CFLAGS) -o $@ $(OBJS_DIR)/client.o $(OBJS_DIR)/utils.o -l ft -L ./libft
	@printf "   \033[0;32m[client build success📱]\n\e[0m"


# bonus
bonus          : $(LIBFT) $(OBJS_DIR) $(B_SERVER) $(B_CLIENT) $(B_SRCS_DIR)/minitalk_bonus.h
	@printf "   \033[0;32m[Bonus build success🔨]\n\e[0m"

vpath %.c $(B_SRCS_DIR)

$(OBJS_DIR)/%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(B_SERVER)    : $(B_OBJS)
	@$(CC) $(CFLAGS) -o $(B_SERVER) $(OBJS_DIR)/utils_bonus.o $(OBJS_DIR)/server_bonus.o -l ft -L ./libft

$(B_CLIENT)    : $(B_OBJS)
	@$(CC) $(CFLAGS) -o $(B_CLIENT) $(OBJS_DIR)/utils_bonus.o $(OBJS_DIR)/client_bonus.o -l ft -L ./libft

clean         :
	@make clean -C libft
	@rm -f $(OBJS_DIR)/server.o $(OBJS_DIR)/client.o $(OBJS_DIR)/utils.o $(OBJS_DIR)/server_bonus.o $(OBJS_DIR)/server_bonus.o $(OBJS_DIR)/client_bonus.o $(OBJS_DIR)/utils_bonus.o
	@printf "   \033[0;32m[execute clean🥡]\n\e[0m"

fclean         : clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT) $(B_SERVER) $(B_CLIENT)
	@printf "   \033[0;32m[execute fclean🚽]\n\e[0m"

re             : fclean all

.PHONY : all clean fclean re bonus
