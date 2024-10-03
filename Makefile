INC = inc
OBJ = obj
SRC = src
LIBMX = libmx
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -g
FLAGS = $(CFLAGS) -I $(INC) -I $(LIBMX)/$(INC)
NAME = pathfinder
LIB = libmx.a
DEPS := $(wildcard $(INC)/*.h)
SRCS := $(wildcard $(SRC)/*.c)
_OBJS = $(SRCS:.c=.o)
OBJS = $(subst $(SRC),$(OBJ),$(_OBJS))

all: $(NAME)

$(LIBMX)/$(LIB):
	@make -C $(LIBMX)
$(OBJ)/%.o: $(SRC)/%.c $(DEPS)
	@mkdir -p obj
	@clang $(FLAGS) -c $< -o $@
$(NAME): $(OBJS) $(LIBMX)/$(LIB)
	@clang $(FLAGS) $^ -o $@

.PHONY: clean uninstall reinstall

uninstall: clean
	@rm -f $(NAME)
	@make $@ -C $(LIBMX)

clean:
	@rm -rf $(OBJ)
	@make $@ -C $(LIBMX)

reinstall: uninstall all
