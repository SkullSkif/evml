APP_NAME = pr03
LIB_NAME_SC = libsc
LIB_NAME_MT = libmt
LIB_CNSL = libcnsl.a
CFLAGS = -Wall -Wextra -Werror -I../include
CC = gcc
SRC_EXT = c

SRC_DIR = .
OBJ_DIR = obj
BIN_DIR = bin

APP_PATH = $(BIN_DIR)/$(APP_NAME)
CNSL_PATH = $(BIN_DIR)/$(LIB_CNSL)
LIB_PATH = ../mySimpleComputer/bin/$(LIB_NAME_SC).a ../myTerm/bin/$(LIB_NAME_MT).a
APP_SOURCES = $(wildcard $(SRC_DIR)/print*.$(SRC_EXT))
CON_VAR = variables.c
CON_VAR_OBJ = $(OBJ_DIR)/variables.o
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/%.o)
DEPS = $(APP_OBJECTS:.o=.d)

.PHONY: all clean

all: $(BIN_DIR) $(OBJ_DIR) $(CNSL_PATH) $(CON_VAR_OBJ) $(LIB_PATH) $(APP_PATH)

-include $(DEPS)

$(BIN_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

$(CON_VAR_OBJ) : $(CON_VAR)
	$(CC) -MMD -c $(CFLAGS) $^ -o $@

$(APP_PATH): $(LIB_PATH) $(CNSL_PATH)
	$(CC) $(CFLAGS) test.c $(CNSL_PATH) $(LIB_PATH) -o $@ 

$(CNSL_PATH) : $(APP_OBJECTS) $(CON_VAR_OBJ)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	$(CC) -MMD -c $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)