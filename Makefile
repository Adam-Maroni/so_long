NAME = so_long
CC = clang
FLAGS = -Wall -Werror -Wextra -g
LIBFT_PATH = inc/libft
LIBFT = $(LIBFT_PATH)/libft.a
MINILIBX_PATH = inc/minilibx-linux
MINILIBX = $(MINILIBX_PATH)/libmlx_Linux.a
INC = inc/ \
      $(LIBFT_PATH) \
      $(MINILIBX_PATH)
SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/, \
      parsing.c \
      readfile.c \
      main.c \
      )
OBJ_PATH = obj
OBJ = $(addprefix $(OBJ_PATH)/, $(notdir $(SRC:.c=.o)))



all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX)  $(OBJ)
	$(CC) $(FLAGS) $(addprefix -I, $(INC))  $(OBJ) $(LIBFT) $(MINILIBX) -o $(NAME)
	
$(LIBFT): 
	(cd $(LIBFT_PATH) && make)

$(MINILIBX):
	(cd $(MINILIBX_PATH) && ./configure)
	
$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	$(CC) $(FLAGS) $(addprefix -I, $(INC)) -c $< -o $@ 

clean: 
	rm -rf $(OBJ)
	(cd $(MINILIBX_PATH) && make clean)
	(cd $(LIBFT_PATH) && make clean)

fclean: clean
	(cd $(LIBFT_PATH) && make fclean)
	rm -rf $(NAME)

re: fclean all


debug: $(LIBFT) $(MINILIBX) $(OBJ)
	$(CC) $(FLAGS) $(addprefix -I, $(INC))  $(OBJ) $(LIBFT) $(MINILIBX) -o $(NAME)
	gdb -x tests/gdbscripts/1.gdb --args ./$(NAME) ./tests/valid_maps/valid0.ber

