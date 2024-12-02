# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 08:11:10 by eaqrabaw          #+#    #+#              #
#    Updated: 2024/12/02 08:52:35 by eaqrabaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = push_swap
CC = cc
Flags = -Wall -Wextra -Werror
SRCS = main stack operations basic_ops double_ops aops bops \
		error sorting_small sorting_utils sorting_large_utils sorting_large
srcDir = srcs/
incDir = includes/
objDir = obj/
libftDir = $(incDir)/libft
INCs = push_swap.h
Srcs = $(addprefix $(srcDir), $(addsuffix .c, $(SRCS)))
OBJ = $(Srcs:$(srcDir)%.c=$(objDir)%.o)
INC = $(addprefix $(incDir), $(INCs))

all : $(Name)

$(Name) : $(OBJ) $(libftDir)/libft.a
	$(CC) $(Flags) -o $(Name) $(OBJ) -L$(libftDir) -lft

$(objDir)%.o: $(srcDir)%.c $(INC) | $(objDir)
	@$(CC) $(Flags) -c $< -o $@

$(objDir):
	@mkdir -p $(objDir)

clean :
	@rm -rf $(objDir)
	$(MAKE) -C $(libftDir) clean

fclean : clean
	@rm -f $(Name)
	$(MAKE) -C $(libftDir) fclean

re : fclean all
	$(MAKE) -C $(libftDir) re
	
$(libftDir)/libft.a:
	$(MAKE) -C $(libftDir)

.PHONY : all clean fclean re