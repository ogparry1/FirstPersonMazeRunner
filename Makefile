BINS=MazeEscape
SRC_FILES=src/*.cpp
OBJ_FILES=obj/*.o

all: 
	g++ -pthread -o ${BINS} ${SRC_FILES}
