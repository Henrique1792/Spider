CC=g++
SRC=src/main.cpp
LIBS = -lGL -lglut -lGLU -lm





all: 
	$(CC) $(SRC) -o build/boris  $(LIBS)

run:
	./build/boris 1366 768

clean:
	rm build/boris
