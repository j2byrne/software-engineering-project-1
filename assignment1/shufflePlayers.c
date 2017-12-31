#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "operations.h"

void shufflePlayers(user players[], int size)
{
	int i, j;
	user tmp;
	bool sameType; // boolean to ensure that no players of the same type are beside each other
	srand(time(NULL)); // seed the rand function

	// fisher yates shuffle algorithm
	for (i = 0; i < size; i++)
	{
		j = rand()%(i+1); // picking a random number between 0 and i
		// if i and j are different swap the player structures in the array
		if (i != j)
		{
			// swapping two player structures
			tmp = players[i];
			players[i] = players[j];
			players[j] = tmp;
		}
	}

	/* ensure that no players of the same type are beside each other, sameType is set as true when there are two players with the same type beside each other,
	 * if there are two players of the same type that are side by side, try to find a gap in the array where the player wouldn't be beside players of the same type,
	 * if it runs through the array 10 times and conditions still cannot be met the function is called again to shuffle and ensure that there are no players of the
	 * same type side by side
	 */
	j = 0;
	do
	{
		sameType = false;
		// go through the array of player structures
		for (i = 0; i < size; i++)
		{
			if (strcmp(players[i].type, players[i+1].type) == 0) // check if two player types are side by side
			{
				//j = (size-1 + i - 2)%(size); // j = i-2, to ensure i does not go below zero and continue decreasing from the highest number i.e. size, the modulus of the size is taken of size-1 +i-2
				int k = 0;

				while (k < size)
				{
					// check if a gap in the array exists where the player won't be beside players of the same type
					if (j != i && players[j-1].type != players[i].type && players[j+1].type != players[i].type)
					{
						// swap two player structures
						tmp = players[i];
						players[i] = players[k];
						players[k] = tmp;
					}
					k++;
				}
				sameType = true; // sameType is set as false
			}
		}
		j++; // increment j
	} while (sameType == true && j < 50); // iterating the loop until sameType is equal to false or if j >= 50, i.e. shuffle conditions cannot be done

	if (sameType == true) // if shuffling conditions cannot be done
	{
		printf("The players cannot be shuffled with two players of the same type being beside each other\n"); // print message
	}

	return;
}
