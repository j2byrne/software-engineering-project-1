#include <stdio.h>
#include "operations.h"

void sortSlot(board slots[], int size)
{
	int i,  row;
	board tmp;

	// find the array number of the last element
	row = -1;
	while (slots[++row].next != 0);

	// sort array
	for (i = size-1; i > 0; i--)
	{
		// swap i+1th element and row+1th element
		tmp = slots[row];
		slots[row] = slots[i];
		slots[i] = tmp;

		// find the array number of the previous slot (i.e. the previous slot as if the array was ordered)
		row = -1;
		while (slots[i].position != slots[++row].next);
	}

	printf("\n-------Initial List of Slots-------\n"); // print text

	displaySlotsList(slots, size); // call the displaySlotsList function
}
