BINS=MazeEscape
SRC_DIR=src
OBJ_DIR=obj
INC_DIR=include
SRC_FILES=$(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.cpp))
OBJ_FILES=$(foreach dir, $(OBJ_DIR), $(wildcard $(dir)/*.o))
INC_FILES=$(foreach dir, $(INC_DIR), $(wildcard $(dir)/*.hpp))

CXX=g++
CFLAGS= -c -g
LDFLAGS=-pthread

all: $(BINS)
	echo $(SRC_FILES)

$(BINS): $(OBJ_FILES)
	$(CXX) $(LDFLAGS) -o $@ $^

$(OBJ_FILES): $(SRC_FILES) $(INC_FILES) 
	$(CXX) $(CFLAGS) -o $@ $(SRC_FILES)

.PHONY: clean

clean:
	rm -f $(OBJ_FILES) $(BINS)
