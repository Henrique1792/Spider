# using gcc compiler
CC = gcc

# output path and filename
BINARY = ./build/output

# includes directory
INCLUDES = ./includes

# libraries and flags
LIBS = -lglut -lGL -lGLU -lm
# FLAGS = -Wall -O0 -g -Wextra -pthread
FLAGS = -O0 -g -pthread

all: compile run clean

compile:
	$(CC) -o $(BINARY) -I$(INCLUDES) $(SRC) $(LIBS) $(FLAGS)

test:
	run clean debug

run:
	$(BINARY)

clean:
rm *.o