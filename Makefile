# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvigne <bvigne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 12:44:05 by bvigne            #+#    #+#              #
#    Updated: 2018/05/17 16:57:18 by bvigne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc $(FLAG)
FLAG = -Wall -Wextra -Werror

SRCS_PATH = ./sources
SRCS = ft_printf.c 					\
	   parsing.c					\
	   get_flags.c					\
	   get_conv.c 					\
	   conv_c.c						\
	   conv_id.c					\
	   conv_maj_d.c					\
	   conv_maj_o.c					\
	   conv_maj_u.c					\
	   conv_maj_x.c					\
	   conv_o.c						\
	   conv_p.c						\
	   conv_s.c						\
	   conv_u.c						\
	   conv_x.c						\
	   lib_put.c 					\
	   lib_nbr.c					\
	   lib_str.c					\
	   lib_str_2.c					\
	   lib_join.c					\
	   lib_conv.c


INC_PATH = ./includes
INC = -I $(INC_PATH)

OBJ_PATH = ./objects
OBJ = $(SRCS:.c=.o)
OBJP = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))

all: $(OBJ_PATH) $(NAME)

re: fclean all

$(OBJ_PATH):
	@mkdir objects
	
$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c
	$(CC) $(INC) -o $@ -c $^

$(NAME): $(OBJP)
	@ar rc $(NAME) $(OBJP)
	@ranlib $(NAME)
	@echo "${_GREEN}${_IGREY}$(NAME) created${_END}"

clean:
	@rm -rf $(OBJP)
	@echo "${_RED}${_IGREY}objects removed${_END}"

fclean: clean
	@rm -rf $(NAME)
	@echo "${_RED}${_IGREY}$(NAME) removed${_END}"

###############################################################################

# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m'
_BOLD=$'\x1b[1m'
_UNDER=$'\x1b[4m'
_REV=$'\x1b[7m'

# Colors
_GREY=$'\x1b[30m'
_RED=$'\x1b[31m'
_GREEN=$'\x1b[32m'
_YELLOW=$'\x1b[33m'
_BLUE=$'\x1b[34m'
_PURPLE=$'\x1b[35m'
_CYAN=$'\x1b[36m'
_WHITE=$'\x1b[37m'

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m'
_IRED=$'\x1b[41m'
_IGREEN=$'\x1b[42m'
_IYELLOW=$'\x1b[43m'
_IBLUE=$'\x1b[44m'
_IPURPLE=$'\x1b[45m'
_ICYAN=$'\x1b[46m'
_IWHITE=$'\x1b[47m'

###############################################################################
