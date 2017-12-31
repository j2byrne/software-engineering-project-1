#include <stdio.h>
#include "operations.h"

int readPlayerFile(user players[])
{
	FILE *fp;
	char tmp[200]; // string to get input from file
	int lineNum = 0; // number of lines in the text file

	fp = fopen("players.txt", "r"); // opening the players.txt

	if (fp == NULL) // checking if there is an error opening the file
		perror("Error opening the player text file"); // printing error
	else
	{
		while ( fgets(tmp, sizeof(tmp), fp) != NULL ) // assigning a line from the players.txt in the tmp array
		{
			sscanf(tmp, "%s %*s %*s %[^\n]", players[lineNum].type, players[lineNum].name); // assigning the correct strings into the players structure array
			lineNum++; // incrementing lineNum
		}
	}
	return lineNum; // return the number of rows of data there are
}
