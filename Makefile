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

all: compile run clean

compile:
	$(CC) -o $(BINARY) -I$(INCLUDE) $(SRC) $(LIBS) $(FLAGS)

run:
	$(BINARY)

clean:
	rm ./build/output