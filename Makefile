CC = clang
CFLAGS = -Wall -Werror -Wextra
LIBFT_PATH = inc/libft
MINILIBX_PATH = inc/minilibx-linux
SRC_PATH = src
SRC = $(addprefix $(SRC_PATH)/, parsing.c get_next_line.c)
OBJ_PATH = obj
OBJ = $(addprefix $(OBJ_PATH)/, parsing.o get_next_line.o)
INC = \
 inc/ \
 $(LIBFT_PATH) \
 $(MINILIBX_PATH)
OUT = so_long


all: minilibx libft $(OBJ)
	$(CC) $(CFLAGS) $(addprefix -I, $(INC))  $(OBJ) -lft -L$(LIBFT_PATH) -lmlx -L$(MINILIBX_PATH) -o $(OUT)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(addprefix -I, $(INC))  -lft -L$(LIBFT_PATH) -lmlx -L$(MINILIBX_PATH) -c $< -o $@ 

clean: 
	rm -rf $(OBJ)
	(cd $(MINILIBX_PATH) && make clean)
	(cd $(LIBFT_PATH) && make clean)

minilibx:
	(cd $(MINILIBX_PATH) && ./configure)
	
libft: 
	(cd $(LIBFT_PATH) && make)

debug:
	$(CC) -g $(addprefix -I, $(INC))  $(OBJ) -lft -L$(LIBFT_PATH) -lmlx -L$(MINILIBX_PATH) -o $(OUT)
	gdb 
