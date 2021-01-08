/****************************************************************/
/*                                                              */
/* decodeMaze.c                                                 */             
/*                                                              */
/* This program consists of functions and procedures            */             
/* that are used encode, decode, and display mazes. This        */             
/* program takes in no arguments and is merely a demonstration  */ 
/*                                                              */
/* Usage: decodeMaze										    */            
/*                                                              */
/****************************************************************/

#include <stdio.h>
#include "decodeMaze.h"

int main() {
	//Integer array of size 32 representing a 32 by 32 char array 
	int maze[32] =  {
		-1, 
		-2146430423,
		-1109928277,
		-1525661045,
		-1602496045,
		-1358950569,
		-1451509759,
		-1927115297,
		-1578180479,
		-1354977603,
		-1476294999,
		-2084818261,
		-1163749757,
		-1964319689,
		-1341614619,
		-1750141691,
		-1256060947,
		-1515522751,
		-1204136611,
		-1955867371,
		-1190652827,
		-1553272339,
		-1100839163,
		-1999963019,
		-631368865,
		-1882138047,
		-1172944163,
		-1412279803,
		-1567107339,
		-164346691,
		-2138762879,
		-1
	};

	printf("Printing Encoded Maze\n");
	printEncodedMaze(maze, 32);
	printf("\n\n");
	
	int path[32] = {0, 0, 0, 0, 12, 8, 56, 32, 8032, 4416, 134115648, 67354944, 67109184,
		67109312, 133169152, 1048576, 1835008, 262144, 262144, 262144, 458752,
		65536, 65536, 65536, 65536, 983040, 67633152, 67633152, 201850880,
		164102144, 259522560, 0};

	printf("Printing Encoded Maze With Path\n");
	if (isPathInMaze(maze, path, 32)) {
		printf("*******************************\n");
		printf("* The Path Fits Into The Maze *\n");
		printf("*******************************\n");
	}
	printEncodedMazeWithPath(maze, path, 32);
	printf("\n\n");

	//Hardcoded versions of the 8 by 8 mazes in question 4
	char maze1[8][8] =   {{1,1,1,1,1,1,1,1},
							{1,0,0,0,1,0,0,1},
							{1,0,1,0,1,1,0,1},
							{1,0,1,0,0,0,0,1},
							{1,0,1,1,1,1,0,1},
							{1,0,0,0,0,0,0,1},
							{1,0,1,0,1,0,1,1},
							{1,1,1,1,1,1,1,1}};

	char maze2[8][8] =  {{1,1,1,1,1,1,1,1},
							{1,0,0,0,0,1,0,1},
							{1,1,1,1,0,1,0,1},
							{1,0,0,1,0,1,1,1},
							{1,1,0,0,0,0,0,1},
							{1,1,1,1,0,1,1,1},
							{1,0,0,0,0,1,0,1},
							{1,1,1,1,1,1,1,1}};

	char maze3[8][8] =   {{1,1,1,1,1,1,1,1},
							{1,0,1,0,0,0,1,1},
							{1,0,1,0,1,0,0,1},
							{1,0,1,0,1,0,1,1},
							{1,0,1,0,1,0,1,1},
							{1,0,1,0,1,0,1,1},
							{1,0,0,0,1,0,0,1},
							{1,1,1,1,1,1,1,1}};

	char maze4[8][8] =  {{1,1,1,1,1,1,1,1},
							{1,0,1,0,1,0,1,1},
							{1,0,1,0,0,0,0,1},
							{1,0,0,0,1,1,1,1},
							{1,1,1,0,1,0,0,1},
							{1,0,0,0,0,0,1,1},
							{1,1,0,1,1,0,0,1},
							{1,1,1,1,1,1,1,1}};

	// Declaration of the integer version of the encoded mazes above	
	int eMaze1[8];
	int eMaze2[8];
	int eMaze3[8];
	int eMaze4[8];

	encode8by8Maze(maze1, eMaze1);
	printf("Encoded Version of Maze 1\n");
	printEncodedMaze(eMaze1, 8);
	printf("\n\n");
	
	encode8by8Maze(maze2, eMaze2);
	printf("Encoded Version of Maze 2\n");
	printEncodedMaze(eMaze2, 8);
	printf("\n\n");

	encode8by8Maze(maze3, eMaze3);
	printf("Encoded Version of Maze 3\n");
	printEncodedMaze(eMaze3, 8);
	printf("\n\n");

	encode8by8Maze(maze4, eMaze4);
	printf("Encoded Version of Maze 4\n");
	printEncodedMaze(eMaze4, 8);
	printf("\n\n");

	// Declaration of an array of size 14 to represent the merge of 4, 8 by 8 character array
	int mergedMaze[14];

	merge8by8Mazes(eMaze1, eMaze2, eMaze3, eMaze4, mergedMaze);
	printf("Encoded Version Of The 4 Merged Mazes\n");
	printEncodedMaze(mergedMaze, 14);
	printf("\n\n");

	// Declaration of varaibles
	int* encoded8by8Mazes[4] = {eMaze1, eMaze2, eMaze3, eMaze4};
	int tempMergedMaze[14];
	int tempPath[14] = {0, 4096, 4096, 4096, 4096, 7936, 256, 256, 448, 112, 16, 28, 6, 0};
	int count = 0;

	// For loop that loops through all possible combinations of the 8 by 8 character mazes to be
	// Merged and then displays them
	// If the path we have described above as "tempPath" is able to maneuver through the maze without
	// Hitting a '1' in the merged maze, the output will display that the path is valid 
	// If the path is valid, the count will be incremented by 1	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 4; l++) {
					merge8by8Mazes(encoded8by8Mazes[i], encoded8by8Mazes[j], encoded8by8Mazes[k],
								 encoded8by8Mazes[l], tempMergedMaze);
					printf("Encoded Version of %d, %d, %d, %d Maze:\n", i+1, j+1, k+1, l+1);
					if (isPathInMaze(tempMergedMaze, tempPath, 14)) {
						printf("********************************\n");
						printf("* The Path Fits Into This Maze *\n");
						printf("********************************\n");	
						count++;
					}
					printEncodedMaze(tempMergedMaze, 14);
					printf("\n\n");
				}
			}	
		}
	}	
	
	// Displays the count of mazes that the path was valid for out of the 256,
	// 8 by 8 mazes combinations.
	// Note: Note required, but is useful for error testing if you know the
	// The result beforehand or just wish to count the successful paths
	printf("The path fits into %d maze combinations.\n", count++);
}

// This function tells us whether the bit at [index] is set
// or not
// Returns whether the bit at the specified [index] of the input
// integer is a "0" or a "1", as  "0" is considered "false" and
//  "1" is considered "true"
int isBitSet(int num, int index) {
	return (num & (1 << index)) >> index;
}

// This function sets the bit at [index] of the input integer
// to "1" and returns the modified integer. If the bit at [index]
// is already set to "1", this function will just be returning 
// the same integer as was inputted 
int setBit(int num, int index) {
	return (num | (1 << index));
}

// This function sets the bit at [index] of the input integer
// to "0" and returns the modified integer. If the bit at [index]
// is already set to "0", this function will just be returning 
// the same integer as was inputted 
int clearBit(int num, int index) {
	return (num & (~(1 << index)));
}

// This procedure takes in an integer array with [size] elements
// That's bits represent a maze and  displays its bits
// If a bit is set to "1", this procedure will display a "@"
// If a bit is set to "0", nothing will be displayed and a blank
// Space will take its place
void printEncodedMaze(int maze[], unsigned char size) {
	for (int i = 0; i < size; i++) {
		for (int j = size-1; j >= 0; j--) {
			if (isBitSet(maze[i], j)) {
				printf("@");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}
}

// This procedure takes in an integer array that's bits represent
// A maze and a second integer array that's bits represent a path
// As well as the size of both arrays and displays both the maze 
// And the path. If a maze and a path bit are both set (overlap)
// The maze bit takes precedent and the character representing a
// The maze will be displayed
// To represent a bit that should be a maze, a "@" will be displayed
// To represent a bit that should be a path, a "." will be displayed
// If both the bit of a maze and a path are "0", a blank space will
// Be displayed
// Assumption: Both the maze and path should be the same length
void printEncodedMazeWithPath(int maze[], int path[], unsigned char size) {
	for (int i = 0; i < size; i++) {
		for (int j = size-1; j >= 0; j--) {
			if (isBitSet(maze[i], j)) {
				printf("@");
			} else if (isBitSet(path[i], j)) {
				printf(".");
			} else {
				printf(" ");	
			}
		}
		printf("\n");
	}	
	return;
}

// This procedure takes an 8 by 8 char maze as an input as well as
// A integer array of length 8 to be modified. This procedure loops
// Through the 8 by 8 char maze, if the value of the char is "1"
// It will set the corresponding bit of the same row in the encoded Maze
// to "1". If the value was "0", it will set the corresponding bit to "0"
void encode8by8Maze(char inputMaze[8][8], int encodedMaze[8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (inputMaze[i][j] == 1) {
				encodedMaze[i] = setBit(encodedMaze[i], 7 - j);
			} else {
				encodedMaze[i] = clearBit(encodedMaze[i], 7 - j);
			}
		}	
	}
	return;	
}

// This procedure takes in 4, 8 by 8 mazes to be merged as well as an
// Integer array of size 14 to be modified. The procedure will iterate
// Through the element in our [finalMaze] and derive whether the bit
// At each index should be set to "0" or "1" based on the corresponding
// Bit in the corresponding 8 by 8 mazes. 
// The top left maze will represent the first 7 rows and first 7 columns
// The top right maze will represent the last 7 rows and first 7 columns
// The bottom left maze will represent the first 7 rows and last 7 columns
// The bottom right maze will represent the last 7 rows and last 7 columns
// Creating a 14 by 14 mazes modeled as such
void merge8by8Mazes(int topLeft[8], int topRight[8], int bottomLeft[8], int bottomRight[8], int finalMaze[14]) {		
	for (int i = 0; i < 14; i++) {
		if (i < 7) {
			for (int j = 13; j >= 7; j--) {
				if (isBitSet(topLeft[i], j - 6)) {
					finalMaze[i] = setBit(finalMaze[i], j);
				} else {
					finalMaze[i] = clearBit(finalMaze[i], j);
				}
			}
			for (int j = 6; j >= 0; j--) {
				if (isBitSet(topRight[i], j)) {
					finalMaze[i] = setBit(finalMaze[i], j);
				} else {
					finalMaze[i] = clearBit(finalMaze[i], j);
				}
			}
		} else {
			for (int j = 13; j >= 7; j--) {
				if (isBitSet(bottomLeft[i-6], j - 6)) {
					finalMaze[i] = setBit(finalMaze[i], j);
				} else {
					finalMaze[i] = clearBit(finalMaze[i], j);
				}
			}
			for (int j = 6; j >= 0; j--) {
				if (isBitSet(bottomRight[i-6], j)) {
					finalMaze[i] = setBit(finalMaze[i], j);
				} else {
					finalMaze[i] = clearBit(finalMaze[i], j);
				}
			}
		}
	}
	return;
}


// This functiontakes in an integer array that represents the bits of the 
// Maze array in two's compliment, a secodn integer array that represents the
// Bits of the path array in two's compliment, as well as the size of both arrays.
// The function will iterate through all bits of the integer arrays, if any two
// Bits at the same index are both set to "1", this would represent an overlap of
// The maze wall and path, therefore, the path would not be valid for this maze.
// A "0" will be returned if an overlap occurrs.
// A "1" will be returned if no overlap occurrs. 
char isPathInMaze(int maze[], int path[], unsigned char size) {
	for (int i = 0; i < size; i++) {
		for (int j = size-1; j >= 0; j--) {
			if (isBitSet(maze[i], j) && isBitSet(path[i], j)) {
				return 0;
			}
		}
	} 
	return 1;
}
