/*
 * main.c
 *
 *  Created on: 3 Feb 2017
 *      Author: james
 */
#include <stdio.h>
#include "operations.h"

int main(void)
{
	int size;
	char tmp;
	user players[20]; // array of the structure user called players
	board slots[20]; // array of the structure user called players

	printf("Welcome to Crossfire\n"); // print text

	do
	{
		printf("Enter 'p' if you want to sort and shuffle a list of players or enter 's' if you want to sort a list of slots: "); // prompt
		tmp = getchar();
		getchar(); // read newline so that if user intputs an invalid character, getchar wont read the newline

		if (tmp == 'p')
		{
			size = readPlayerFile(players); // calling readPlayerFile function
			shufflePlayers(players, size); // call shufflePlayers function
			displayPlayersList(players, size); // call displayPlayersList function
			sortPlayers(players, size); // call sortPlayers function
			displayPlayersList(players, size); // call displayPlayersList function
		}
		else if (tmp == 's')
		{
			size = readSlotFile(slots); // calling readSlotFile function
			sortSlot(slots, size); // call sortSlots function
		}
	} while (tmp != 'p' && tmp != 's');

	return 0;
}
