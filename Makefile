# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bterral <bterral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 09:22:12 by bterral           #+#    #+#              #
#    Updated: 2022/02/07 12:31:41 by bterral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:= push_swap

SRCS_FILES 			:= actions.c error.c lst_utils.c push_swap.c \
						sorting_large.c sorting_small.c stack_utils.c

SRCS_DIR			:= ./srcs/

SRCS				:= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

LST_OBJS			:= $(SRCS_FILES:.c=.o)

OBJS_DIR			:= ./.objs/

OBJS				:= $(addprefix $(OBJS_DIR), $(LST_OBJS))

INCLUDES_DIR		:= ./includes/

INCLUDES			:= ./includes/push_swap.h

### LIB ###

LIBFT_DIR 			:= ./libft

LIBFT_LIB 			:= ./libft/libft.a

SRCS_FILES_LIBFT	:= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
						ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
						ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
						ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
						ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
						ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
						ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

SRCS_DIR_LIBFT 		:= ./libft/

SRCS_LIBFT			:= $(addprefix ${SRCS_DIR_LIBFT},${SRCS_FILES_LIBFT})

OBJS_LIBFT			:= ${SRCS_LIBFT:.c=.o}

INCLUDES_LIBFT		:= ./libft/libft.h

### COMMANDS ###

CC					:= gcc

CFLAGS				:= -Wall -Wextra -Werror

RM					:= rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS_DIR)%o: $(SRCS_DIR)%c $(INCLUDES) Makefile | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT_LIB): $(OBJS_LIBFT) $(INCLUDES_LIBFT)
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $^ -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all