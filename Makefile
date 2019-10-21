NAME	=	lem-in

SRC_F	=	bfs.c \
			validation.c \
			help_func.c \
			my_exit.c \
			lem_in.c \
			parsing.c \
			parsing_help.c \
			parse_rooms_ants.c \
			put_print_way.c \
			read_inf.c

SRC = $(addprefix ./src/, $(SRC_F))

OBJ_F 	=	bfs.o \
			validation.o \
			help_func.o \
			my_exit.o \
			lem_in.o \
			parsing.o \
			parsing_help.o \
			parse_rooms_ants.o \
			put_print_way.o \
			read_inf.o

OBJ_DIR =	./obj/

OBJ = $(addprefix ./obj/, $(OBJ_F))

LIB = ./libft
LIB_OBJ = ./libft/*.o

HEADER = ./src/lem_in.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(HEADER)
	 	@make -C $(LIB)
		@gcc $(OBJ) $(LIB_OBJ) -o $(NAME) -O3 $(FLAGS)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(addprefix ./obj/, %.o): $(addprefix ./src/, %.c) $(HEADER)
		@gcc -o $@ -c $< -O3 $(FLAGS)

lib:
	@make -C $(LIB) re
clean:
	@make -C $(LIB) clean
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(NAME)

re: fclean all
