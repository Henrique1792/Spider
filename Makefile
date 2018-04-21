# Using gcc compiler
CC = gcc

# Output path and filename
BINARY = ./build/output

# Includes directory
INCLUDE = ./include

SRC = ./src/main.c ./src/scene.c ./src/spider.c

# Libraries 
LIBS = -lglut -lGL -lGLU -lm

# Flags
FLAGS = -Wall -O0 -g -Wextra -pthread

#.PHONY: Execute the method, even if the files compiled exist -
#        phoning compile obliges it to compile everything every compilation =)
.PHONY: compile
all: compile run clean
compile:
	$(CC) -o $(BINARY) -I$(INCLUDE) $(SRC) $(LIBS) $(FLAGS)
	ctags -R *

run:
	$(BINARY)

debug:
	valgrind ./build/boris
clean:
	rm ./build/output