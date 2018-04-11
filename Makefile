CC=gcc

SRC_DIR=src
OBJ_DIR=build


SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o,$(SRCS))
LIBS = -lGL -lglut -lGLU -lm -g
BUILD=build/*
.PHONY: all



all: $(OBJS)
	$(CC)  -o build/boris  $^ $(LIBS) && ctags -R *


$(OBJ_DIR)/%.o:
	$(CC) -c $(patsubst $(OBJ_DIR)/%.o, $(SRC_DIR)/%.c, $@) -o $@
run:
	./build/boris 1366 768

clean:
	rm $(BUILD) tags
