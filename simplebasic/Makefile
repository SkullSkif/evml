CC = gcc
CFLAGS = -std=c11 -I../mySimpleComputer
SRCDIR = .
OBJ_DIR = ./obj
LIBDIR = .

OBJSLINK := $(wildcard $(OBJ_DIR)/*.o)

LIB_FILE = $(OBJ_DIR)/libSimpleBasic.a

SRCS := $(filter-out $(SRCDIR)/main.c, $(wildcard $(SRCDIR)/*.c))
OBJS := $(patsubst $(SRCDIR)/%,$(OBJ_DIR)/%,$(SRCS:.c=.o))

build: $(LIB_FILE) sb

sb: $(LIB_FILE)
	gcc -c main.c -o main.o -I../include -I../mySimpleComputer
	gcc main.o $(OBJSLINK)-o sb -L$(LIBDIR)/obj -lSimpleBasic -L../console/obj -lMySimpleComputer

$(LIB_FILE): $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRCDIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I../include -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) *.a *.o *.out sbt

.PHONY: clean
