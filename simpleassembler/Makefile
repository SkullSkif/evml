CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -I../mySimpleComputer
SRCDIR = .
OBJ_DIR = ./obj
LIBDIR = .

LIB_FILE = $(OBJ_DIR)/libSimpleAssembler.a

SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%,$(OBJ_DIR)/%,$(SRCS:.c=.o))

build: $(LIB_FILE) sa

sa: $(LIB_FILE) $(OBJSLINK)
	$(CC) main.c -o sa $(CFLAGS) -I../include -I../mySimpleComputer -L$(LIBDIR)/obj -lSimpleAssembler -L../console/obj -lMySimpleComputer

$(LIB_FILE): $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRCDIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I../include -c -o $@ $<
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) *.a *.o *.out sat

.PHONY: clean
