NAME            = pushswap.a

CC              = cc
CFLAGS          = -Wall -Wextra -Werror
AR              = ar
ARFLAGS         = rcs
RM              = rm -rf

SRC             = main.c mergesort.c roundlist.c

OBJ_DIR         = obj
OBJS            = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

LIBFT_PATH      = ./libft
LIBFT           = $(LIBFT_PATH)/libft.a

all:            $(NAME)

$(NAME):        $(LIBFT) $(OBJ_DIR) $(OBJS)
			cp $(LIBFT) $(NAME)
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR):
				mkdir -p $(OBJ_DIR)
$(OBJ_DIR)/%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@
$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJ_DIR)

fclean: 		clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re