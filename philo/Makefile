# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 12:21:20 by jcheel-n          #+#    #+#              #
#    Updated: 2023/07/20 02:43:19 by jcheel-n         ###   ########.fr        #
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

PHILO_SRC	=	main.c checker.c fill_info.c create_threads.c create_philo.c create_mutex.c#create_table.c states.c 

SRCS	+=	$(addprefix $(SRC_DIR), $(PHILO_SRC))
OBJS	=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS	=	$(addsuffix .d, $(basename $(OBJS)))

$(OBJ_DIR)%.o: %.c Makefile
	@$(MD) $(dir $@)
	@echo "	Compiling: $<"
	$(CC) -MT $@ -MMD -MP $(CFLAGS) $(INCLUDE) -c $< -o $@

all: ${NAME}

${NAME}: $(OBJS)
	@$(CC) $(CFLAGS) $(XFLAGS) $(LIBFT) $(OBJS) -o $(NAME)
	@echo "Philo compiled."

clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@${RM} ${NAME}

re: fclean all

norm: 
	norminette $(SRCS)

-include $(DEPS)

.PHONY: norm clean fclean re all
