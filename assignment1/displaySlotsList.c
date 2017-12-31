#include <stdio.h>
#include "operations.h"

void displaySlotsList(board slots[], int size)
{
	int i;

	// for loop to display the slots
	for (i = 0; i < size; i++)
	{
		printf("(%d,%s)", slots[i].position, slots[i].type); // print structure data
		if (i != size-1) // if not the last element in the array of structures
			printf("->"); // print text
	}
	printf("\n");
}
