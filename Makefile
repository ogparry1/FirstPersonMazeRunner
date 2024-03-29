BINS=MazeEscape
SRC_DIR=src
OBJ_DIR=obj
INC_DIR=include
SRC_FILES=$(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.cpp))
OBJ_FILES=$(foreach dir, $(OBJ_DIR), $(wildcard $(dir)/*.o))
INC_FILES=$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.hpp))

CXX=g++
CFLAGS= -c -g
LDFLAGS= -pthread

all: $(BINS)
	g++ --std=c++11 -g -o MazeEscape src/MazeEscape.cpp -lncurses

.PHONY: clean

clean:
	rm -f $(OBJ_FILES) $(BINS)
