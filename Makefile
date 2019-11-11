CC=gcc
CFLAGS= -Wall -Wextra -Werror

EXEC=readline
SRC= src/main.c src/tstring.c src/history.c
OBJ= $(SRC:.c=.o)

all: $(EXEC)

readline: $(OBJ)
		@$(CC) -o $@ $^ $(LDFLAGS) 

%.o: %.c
		$(CC) -o $@ -c $< $(CFLAGS) -I./include

.PHONY: clean mrproper

clean:
		rm -rf src/*.o

fclean: clean
		rm -rf $(EXEC)
