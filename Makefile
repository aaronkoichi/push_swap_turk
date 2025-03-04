# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 15:36:03 by zlee              #+#    #+#              #
#    Updated: 2025/03/04 22:15:31 by zlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PARSING_FOLDER = ./src/parsing

SORTING_FOLDER = ./src/sorting

PRINTING_FOLDER = ./src/printing


SRC_FOLDER = ./src

TURK_FOLDER = ./src/turk

DATA_PREP = $(SRC_FOLDER)/data_prep/push_swap_prepare_data.c

PARSING = $(PARSING_FOLDER)/push_swap_parsing_numbers_1.c \
          $(PARSING_FOLDER)/push_swap_parsing_numbers_2.c \

TURK =  $(TURK_FOLDER)/turk_sort_main.c \
		$(TURK_FOLDER)/turk_sort_determine_push.c \
		$(TURK_FOLDER)/turk_sort_determine_rotate.c \
		$(TURK_FOLDER)/turk_sort_operation.c \
		$(TURK_FOLDER)/turk_sort_rotate_inst.c \
		$(TURK_FOLDER)/turk_sort_moves.c \
		$(TURK_FOLDER)/turk_sort_execution.c \
		$(TURK_FOLDER)/turk_sort_rotate_all.c

SORTING = $(SORTING_FOLDER)/check_sorted.c \
		  $(SORTING_FOLDER)/retrieve_data.c \
		  $(SORTING_FOLDER)/sort_two_three.c \

SRC = $(DATA_PREP) $(PARSING) $(SORTING) $(TURK)\
	  $(SRC_FOLDER)/push_swap.c \
	  $(SRC_FOLDER)/push_swap_main.c \
	  $(SRC_FOLDER)/push_swap_operation.c \
	  $(PRINTING_FOLDER)/print_inst.c \
	  $(SRC_FOLDER)/pre_sorting/pre_sorting.c \

OBJS = $(SRC:.c=.o)

# CFLAGS = -Wall -Wextra -Werror

CC = cc

LEAK_ERR_CHECK = -fsanitize=address -fsanitize=undefined -g3

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft bonus
	$(CC) $(CFLAGS) $(LEAK_ERR_CHECK) $^ libft/libft.a -o $@

%.o : %.c
	$(CC) $(CFLAGS) $(LEAK_ERR_CHECK)  -I includes/ -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean : clean
	cd libft && rm -f libft.a
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
