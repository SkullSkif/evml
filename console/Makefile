APP_NAME = pr03
LIB_NAME_SC = libsc
LIB_NAME_MT = libmt
LIB_CNSL = libcnsl.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC_EXT = c

SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

APP_PATH = $(BIN_DIR)/$(APP_NAME)
CNSL_PATH = $(BIN_DIR)/$(LIB_CNSL)
LIB_PATH = ../mySimpleComputer/bin/$(LIB_NAME_SC).a
APP_SOURCES = $(wildcard $(SRC_DIR)/print*.$(SRC_EXT))
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/%.o)
DEPS = $(APP_OBJECTS:.o=.d)

.PHONY: all clean

all: $(BIN_DIR) $(OBJ_DIR) $(CNSL_PATH) $(APP_PATH)

-include $(DEPS)

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

$(APP_PATH): $(LIB_PATH) $(CNSL_PATH)
	$(CC) $(CFLAGS) test.c -I../include $^ -o $@ 

$(CNSL_PATH) : $(APP_OBJECTS)
	ar rcs $@ $(APP_OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	$(CC) -MMD -c $(CFLAGS) -I../include $^ -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)