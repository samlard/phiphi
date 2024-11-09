#---------------------------------------------------------#

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g

GFLAGS	=	-g

#DFLAGS	=	-fsanitize=thread
#---------------------------------------------------------#

SRC_DIR	=	src

SRC		=	src/init_struct.c src/main.c src/monitor.c src/parsing.c src/routine.c src/utils_1.c src/utils_2.c src/one_philo.c

OBJ_DIR	=	obj

OBJ		=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INC_DIR	=	include
#---------------------------------------------------------#

NAME	=	philo

all:		$(NAME)

$(NAME):	$(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(DFLAGS) $(GFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DFLAGS) $(GFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
#---------------------------------------------------------#

clean:
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -rf $(NAME) *dSYM

re: fclean all

.PHONY: all fclean clean re
#---------------------------------------------------------#