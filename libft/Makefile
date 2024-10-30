
#---------------------------------------------------------#

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror -g

# GFLAGS	=	-g 

# DFLAGS	=	-fsanitize=address -fsanitize=undefined

#---------------------------------------------------------#

SRC_DIR	=	src

SRC		=	$(shell find $(SRC_DIR) -type f -name "*.c")

OBJ_DIR	=	obj

OBJ		=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INC_DIR	=	include

AR 		=    ar -rc

.PHONY: all lib clean fclean libclean re

#---------------------------------------------------------#

NAME	=	libft.a

all:		$(NAME)

$(NAME):	$(OBJ)
	$(AR) $(NAME) ${OBJ}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#---------------------------------------------------------#

clean:
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -rf $(NAME) *dSYM
	
re: fclean all

#---------------------------------------------------------#