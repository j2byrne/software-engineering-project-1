#include <string.h>
#include "operations.h"

void sortPlayers(user players[], int size)
{
	user tmp;
	int i, j;

	// insertion sort
	for (i = 1; i < size; i++)
	{
		j = i;
		// iterate until the types are in order and the names are in order in the for each type
		while (j > 0 && ((strcmp(players[j].type, players[j-1].type) < 0) || ((strcmp(players[j].type, players[j-1].type) == 0) && (strcmp(players[j].name, players[j-1].name) < 0))))
		{
			// swapping two user structures in the array
			tmp = players[j];
			players[j] = players[j-1];
			players[j-1] = tmp;

			j--; // decrementing j;
		}
	}

	return;
}
