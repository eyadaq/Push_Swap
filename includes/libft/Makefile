# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eaqrabaw <eaqrabaw@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 23:21:58 by eaqrabaw          #+#    #+#              #
#    Updated: 2024/11/30 03:01:10 by eaqrabaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Name = libft.a
CC = cc
AR = ar rcs
Flags = -Wall -Wextra -Werror
SRC = ft_memset ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp ft_itoa ft_atoi ft_calloc \
      ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_strlen ft_tolower \
      ft_strchr ft_strrchr ft_strncmp ft_strlcpy ft_strlcat ft_strnstr ft_strdup ft_substr ft_strjoin ft_strtrim ft_split\
      ft_strmapi ft_striteri ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap \
      ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_atol \
      get_next_line ft_putunsigned ft_putstr_printf ft_putptr ft_printf ft_puthexa

srcDir = src/
headersDIR = headers/
objDir = obj/
SRCS = $(addprefix $(srcDir), $(addsuffix .c, $(SRC)))
OBJS = $(SRCS:$(srcDir)%.c=$(objDir)%.o)

# Default target
all: $(Name)

# Rule for creating the static library
$(Name): $(OBJS)
	@$(AR) $(Name) $(OBJS)

# Rule to create object files in the objDir
$(objDir)%.o: $(srcDir)%.c | $(objDir)
	@$(CC) $(Flags) -c $< -o $@

# Create the object directory if it doesn't exist
$(objDir):
	@mkdir -p $(objDir)

# Clean object files
clean:
	@rm -rf $(objDir)

# Clean everything (object files + library)
fclean: clean
	@rm -f $(Name) 

# Rebuild everything (clean + all)
re: fclean all

.PHONY: all clean fclean re