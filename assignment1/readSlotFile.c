#include <stdio.h>
#include "operations.h"

int readSlotFile(board slots[])
{
	FILE *fp;
	char tmp[200]; // string to get input from file
	int lineNum = 0; // number of lines in the text file

	fp = fopen("slots.txt", "r"); // opening the players.txt

	if (fp == NULL) // checking if there is an error opening the file
		perror("Error opening the slots text file"); // printing error
	else
	{
		while ( fgets(tmp, sizeof(tmp), fp) != NULL ) // assigning a line from the players.txt in the temp array
		{
			sscanf(tmp, "%d %*s %s %d", &slots[lineNum].position, slots[lineNum].type, &slots[lineNum].next); // assigning the correct strings into the players structure array
			lineNum++; // incrementing lineNum
		}
	}
	return lineNum; // return the number of rows of data there are
}
