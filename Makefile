# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlereffa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/26 13:43:21 by jlereffa          #+#    #+#              #
#    Updated: 2017/03/15 03:16:04 by jlereffa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##PROJECT
NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

##DIRECTORIES
SRC_PATH = srcs/
OBJ_PATH = objs/
INC_PATH = includes/
INC_LIBFT_PATH = libs/libft/includes/
LIBFT_PATH = libs/libft/

##FILES
SRC_NAME = main.c\
		   ft_error_return.c\
		   ft_init_t_env.c\
		   ft_convert_linked_structs_to_int_tables.c\
		   ft_convert_path_to_int_tables.c\
		   ft_input_listener_keyboard.c\
		   ft_input_listener_mouse.c\
		   ft_draw_gui_selection_screen.c\
		   ft_draw_gui_selection_screen_original_text_background.c\
		   ft_draw_gui_selection_screen_text.c\
		   ft_draw_quad.c\
		   ft_draw_boxes.c\
		   ft_handle_mouse_input_choices.c\
		   ft_handle_mouse_input_reset_or_close.c\
		   ft_handle_mouse_input_launch.c\
		   ft_launch_fdf_computing.c\
		   ft_print_int_table.c\
		   ft_get_global_values.c\
		   ft_init_mlx_environment.c\
		   ft_malloc_triple_int_tab.c\
		   ft_bigtab_filling.c\
		   ft_print_bigtab.c\
		   ft_trace_links.c\
		   ft_handle_pixel_color.c
		   #ft_apply_representation_choice_to_int_table.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lft
HEADER_PROJECT = fdf.h
HEADER_LIBFT = libft.h

##VARIABLES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIBFT = $(addprefix -L,$(LIBFT_PATH))
INC = $(addprefix -I,$(INC_PATH))
INC_LIBFT = $(addprefix -I,$(INC_LIBFT_PATH))
HEADER = $(addprefix $(INC_PATH),$(HEADER_PROJECT))
HEADER_LIB = $(addprefix $(INC_LIBFT_PATH),$(HEADER_LIBFT))

##RULES
all: $(NAME)

$(NAME): libft $(OBJ)
	@$(CC) $(LIBFT) $(LIB_NAME) $(FRAMEWORK) -o $@ $(OBJ)
	@echo "\n\033[1;34m [$(NAME)] %.o\t\t\033[1;32m[Created]\033[0m"
	@echo "\033[1;34m [$(NAME)] $(NAME)\t\t\033[1;32m[Created]\033[0m"
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) $(HEADER_LIB)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) $(INC_LIBFT) -o $@ -c $<
	@echo "\033[32m█\033[0m\c"
	
clean:
	@rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@make clean -C $(LIBFT_PATH)
	@echo "\033[1;34m [$(NAME)] %.o\t\t\033[1;31m[Removed]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "\033[1;34m [$(NAME)] $(NAME)\t\t\033[1;31m[Removed]\033[0m"

re: fclean all

libft:
	@make -C $(LIBFT_PATH)

.PHONY: libft all clean fclean re
