SRC_DIR := src
OBJ_DIR := obj

NAME := libmx.a
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS= -std=c11 -Wall -Wextra -Werror -Wpedantic

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	clang $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

uninstall: clean
	@$(RM) -f $(NAME)
clean:
	@$(RM) -rf $(OBJ_DIR)

reinstall: uninstall all