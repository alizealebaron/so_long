# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 13:52:08 by alebaron          #+#    #+#              #
#    Updated: 2025/11/22 12:38:57 by alebaron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==========================
#        Constantes
# ==========================

CC      = cc
RM      = rm -rf
NAME    = libft.a
CFLAGS  = -Wall -Wextra -Werror

# ==========================
#         Couleurs
# ==========================

BLACK   := \033[30m
RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE    := \033[96m
MAGENTA := \033[38;5;206m
CYAN    := \033[36m
WHITE   := \033[37m
RESET   := \033[0m
BOLD    := \033[1m

# ==========================
#         Sources
# ==========================

LIB_SRCS = ft_isalpha.c       \
           ft_isdigit.c       \
           ft_isascii.c       \
           ft_isalnum.c       \
           ft_isprint.c       \
           ft_strlen.c        \
           ft_memset.c        \
           ft_bzero.c         \
           ft_memcpy.c        \
           ft_memmove.c       \
           ft_strlcpy.c       \
           ft_toupper.c       \
           ft_tolower.c       \
           ft_strlcat.c       \
           ft_strrchr.c       \
           ft_strchr.c        \
           ft_strncmp.c       \
           ft_strnstr.c       \
           ft_memcmp.c        \
           ft_memchr.c        \
           ft_strdup.c        \
           ft_substr.c        \
           ft_strjoin.c       \
           ft_calloc.c        \
           ft_strtrim.c       \
           ft_split.c         \
           ft_itoa.c          \
           ft_strmapi.c       \
           ft_striteri.c      \
           ft_putchar_fd.c    \
           ft_putstr_fd.c     \
           ft_putendl_fd.c    \
           ft_putnbr_fd.c     \
           ft_atoi.c          \
           ft_lstnew.c        \
           ft_lstadd_front.c  \
           ft_lstsize.c       \
           ft_lstlast.c       \
           ft_lstadd_back.c   \
           ft_lstdelone.c     \
           ft_lstclear.c      \
           ft_lstiter.c       \
           ft_lstmap.c        \
           printf_putchar.c   \
           printf_putaddr.c   \
           printf_putstr.c    \
           printf_putnbr.c    \
           printf_putnbr_u.c  \
           printf_strlen.c    \
           ft_printf.c        \
           get_next_line.c

LIB_OBJS = $(LIB_SRCS:.c=.o)

# ==========================
#         Règles
# ==========================

all: $(NAME)

%.o: %.c
	@echo "$(CYAN)[Compiling]$(RESET) 🦆 $(MAGENTA)$(BOLD)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB_OBJS)
	@echo "\nCompiled with $(GREEN)$(BOLD)$(CFLAGS)$(RESET)"
	@ar -rcs $@ $^
	@echo "$(MAGENTA)$(BOLD)----------------------------------------"
	@echo "     $(NAME) = NOW READY FOR USE!"
	@echo "----------------------------------------$(RESET)"

clean:
	@echo "$(RED)$(BOLD)[Cleaning objects of ${NAME}]$(RESET)"
	@$(RM) $(LIB_OBJS)

fclean: clean
	@echo "$(RED)$(BOLD)[Removing $(NAME)]$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
