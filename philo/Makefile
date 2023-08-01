# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 12:21:20 by jcheel-n          #+#    #+#              #
#    Updated: 2023/07/29 12:12:21 by jcheel-n         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS	= -Wall -Wextra -Werror
XFLAGS	= -fsanitize=address -g2
AR		= ar -rcs
RM		= rm -f
MD		= mkdir -p
CP		= cp -f

SRC_DIR	= src/
INC_DIR	= inc/
OBJ_DIR	= obj/

INCLUDE = -I $(INC_DIR)

LIBFT	= libft/libft.a

PHILO_SRC	=	main.c checker.c initialize_struct.c create_threads.c states.c routine.c delete.c loop.c #create_table.c states.c 

SRCS	+=	$(addprefix $(SRC_DIR), $(PHILO_SRC))
OBJS	=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS	=	$(addsuffix .d, $(basename $(OBJS)))

$(OBJ_DIR)%.o: %.c Makefile
	@$(MD) $(dir $@)
	@$(CC) -MT $@ -MMD -MP $(CFLAGS) $(XFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(COLOUR_BLUE)Compiling $< $(COLOUR_END)"

all: ${NAME}

${NAME}: $(OBJS)
	@$(CC) $(CFLAGS) $(XFLAGS) $(LIBFT)  $(OBJS) -o $(NAME)
	@echo "$(COLOUR_GREEN)Philo compiled$(COLOUR_END)"

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(COLOUR_RED)Dependencies and objects removed$(COLOUR_END)"


fclean: clean
	@${RM} ${NAME}
	@echo "$(COLOUR_RED)Programs removed$(COLOUR_END)"

re: fclean all

norm: 
	norminette $(SRCS)

-include $(DEPS)

.PHONY: norm clean fclean re all

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m
