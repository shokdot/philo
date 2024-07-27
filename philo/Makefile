NAME = philo

SRC_DIR = src
OBJ_DIR = build
SUBDIRS =


INCLUDES = -I includes
HEADER = $(wildcard includes/*.c)

SRCDIRS = $(addprefix $(SRC_DIR)/, $(SUBDIRS))
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

# CFLAGS = -Wall -Wextra -Werror

GREEN = \x1b[32;1m
RED = \x1b[31;1m
RESET = \x1b[0m

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ) Makefile $(HEADER)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(GREEN) Philo is ready!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -r $(OBJ_DIR)

fclean: clean
	@rm -r $(NAME)
	@echo "$(RED) Deleting so_long!$(RESET)"

re: fclean all

.PHONY: all $(NAME) clean re fclean
