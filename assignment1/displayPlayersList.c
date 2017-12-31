#include <stdio.h>
#include "operations.h"

void displayPlayersList(user players[], int size)
{
	int i;
	static int list = 0; // when list = 0, printing shuffled list of players, when list = 1 printing sorted list of players

	if (list == 0)
		printf("\n-------Shuffled List of Players-------\n"); // print text
	else
		printf("-------Sorted List of Players-------\n"); // print text

	// for loop to print the players structures
	for (i = 0; i < size; i++)
	{
		printf("%s\t- %s\n", players[i].type, players[i].name); // print text
	}

	printf("\n"); // print newline

	list++; // increment list

	return;
}
