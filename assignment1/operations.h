/*
 * operations.h
 *
 *  Created on: 14 Feb 2017
 *      Author: james
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_

// A structure to hold the information about a user
typedef struct user {
	char name[20];
	char type[10];
} user;

// A structure to hold the information about the board
typedef struct board {
	int position;
	int next;
	char type[20];
} board;

int readPlayerFile(user players[]); // a function to read the players data from a file
int readSlotFile(board slots[]); // a function to read the slots data from a file
void sortPlayers(user players[], int size); // a function to sort the players alphabetically by their type then by their name
void sortSlot(board slots[], int size); // a function that sorts the slots array
void shufflePlayers(user players[], int size); // a function that shuffles the players array
void displayPlayersList(user players[], int size); // a function that displays the players array
void displaySlotsList(board slots[], int size); // a function that displays the slots array

#endif /* OPERATIONS_H_ */
