# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/30 16:32:46 by ahjadani          #+#    #+#              #
#    Updated: 2022/02/17 12:00:52 by ahjadani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_FILES =	server.c lib/ft_additional_func.c

CLIENT_FILES = client.c lib/ft_additional_func.c lib/ft_atoi.c

CFLAGS = -Werror -Wextra -Wall

SERVER_OBJECTS = $(SERVER_FILES:.c=.o)

CLIENT_OBJECTS = $(CLIENT_FILES:.c=.o)

SERVER = server
CLIENT = client
CC = cc
RM = rm -f

all: $(SERVER) $(CLIENT)
bonus: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJECTS)
	$(CC) $(CFLAGS) $(SERVER_OBJECTS) -o $(SERVER)

$(CLIENT) : $(CLIENT_OBJECTS)
	$(CC) $(CFLAGS) $(CLIENT_OBJECTS) -o $(CLIENT)

%.o:%.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SERVER_OBJECTS) $(CLIENT_OBJECTS)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all, clean, fclean, re, bonus