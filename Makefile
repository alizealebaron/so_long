# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alebaron <alebaron@student.42lehavre.fr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 12:13:38 by alebaron          #+#    #+#              #
#    Updated: 2025/11/27 15:04:38 by alebaron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ==========================
#        Constantes
# ==========================

CC = cc
RM = rm -rf
NAME = ${NAME_MAIN}
CFLAGS = -Wall -Werror -Wextra
NAME_MAIN = so_long
LIB_DIR = sources

# ==========================
#         Couleurs
# ==========================

BLACK   := \033[30m
RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE 	:= \033[96m
MAGENTA := \033[38;5;206m
CYAN    := \033[36m
WHITE   := \033[37m
RESET   := \033[0m
BOLD    := \033[1m
DIM     := \033[2m
ITALIC  := \033[3m
UNDER   := \033[4m
BLINK   := \033[5m
REVERSE := \033[7m
HIDDEN  := \033[8m
PINK 	:= \033[35m

# ==========================
#         Sources
# ==========================

LIB_SRCS = ${LIB_DIR}/so_long.c             \
		   ${LIB_DIR}/init_game.c           \
		   ${LIB_DIR}/so_long_utils.c       \
		   ${LIB_DIR}/so_long_utils2.c      \
		   ${LIB_DIR}/check_error.c         \
		   ${LIB_DIR}/check_error_utils.c   \
		   ${LIB_DIR}/init_minilibx.c       \
		   ${LIB_DIR}/init_visu_map.c       \
		   ${LIB_DIR}/keyboard_press.c      \

LIB_OBJS =  $(LIB_SRCS:.c=.o)

# ==========================
#         LIB_FT
# ==========================

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# ==========================
#         Minilibx
# ==========================

MINI_DIR = ./minilibx-linux
MINI = $(MINI_DIR)/libmlx.a

MLXFLAGS =	-L $(MINI_DIR) -lmlx -lXext -lX11

# ==========================
#         Règles
# ==========================

all: $(LIBFT) $(MINI) $(NAME)

$(MINI):
	@$(MAKE) -C $(MINI_DIR) --no-print-directory

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

%.o: %.c
	@echo "$(CYAN)[Compiling]$(RESET) 🦆 $(BLUE)$(BOLD)$<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIB_OBJS) $(MINI) $(LIBFT) 
	@echo "\nCompiled with $(GREEN)$(BOLD)$(CFLAGS)$(MLXFLAGS)$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(LIB_OBJS) $(MINI) $(LIBFT) $(MLXFLAGS) -g3
	@echo "$(BLUE)$(BOLD)----------------------------------------"
	@echo "     $(NAME) = NOW READY FOR USE!"
	@echo "----------------------------------------$(RESET)"

clean:
	@echo "$(RED)$(BOLD)[Cleaning objects of ${NAME}]$(RESET)"
	@$(MAKE) clean -C $(LIBFT_DIR) --no-print-directory
	@$(MAKE) clean -C $(MINI_DIR) --no-print-directory
	$(RM) $(LIB_OBJS)

fclean: clean
	@echo "$(RED)$(BOLD)[Removing $(NAME)]$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_DIR) --no-print-directory
	$(RM) $(NAME)

re: fclean all

coin: re 
	@echo "$(YELLOW)$(BOLD)                    $(RESET)"
	@echo "$(YELLOW)$(BOLD)    ~Coin coin~     $(RESET)"
	@echo "$(YELLOW)$(BOLD)  _      _      _   $(RESET)"
	@echo "$(YELLOW)$(BOLD)>(.)__ <(.)__ =(^)__$(RESET)"
	@echo "$(YELLOW)$(BOLD) (___/  (___/  (___/$(RESET)"
	@echo "$(YELLOW)$(BOLD)                    $(RESET)"
	@echo "$(YELLOW)$(BOLD)    ~Coin coin~     $(RESET)"

.PHONY: fclean all clean re coin
.SILENT: