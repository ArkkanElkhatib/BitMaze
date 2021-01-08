#include <stdio.h>

void printEncodedMaze(int maze[], unsigned char size);
void printEncodedMazeWithPath(int maze[], int path[], unsigned char size);
void encode8by8Maze(char inputMaze[8][8], int encodedMaze[8]);
int isBitSet(int num, int index);
int setBit(int num, int index);
int clearBit(int num, int index);
void merge8by8Mazes(int topLeft[8], int topRight[8], int bottomLeft[8], int bottomRight[8], int finalMaze[14]);
char isPathInMaze(int maze[], int path[], unsigned char size);
