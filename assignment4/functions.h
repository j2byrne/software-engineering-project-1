/*
 * functions.h]
 *
 *  Created on: 24 Apr 2017
 *      Author: liliana
 */

#define PLAYERS_FILE "players.txt"
#define SLOTS_FILE "slots.txt"

/* This function reads a file and populates playerArray
 * (each row contains a line of the file being read).
 * The function returns the number of players.
 *
 * Input Parameters
 * 	filePath: the file URL
 * 	playerArray: the array being populated with the payers information
 *
 */
int readFile(char * filePath, char playerArray[10][70]);

/*
 * This function sorts the players provided as input alphabetically using the
 * insertion sort algorithm
 *
 * Input Parameters
 * 	playersNum: the number of players
 * 	playerArray: the array of strings containing the players information to be ordered.
 *
 */
void sortPlayers(int playersNum, char playerArray[10][70]);


/*
 * This function shuffles the players provided as input using the
 * Fisher Yates algorithm
 *
 * Input Parameters
 * 	playersNum: the number of players
 * 	playerArray: the array of strings containing the players information to be ordered.
 *
 */
void shufflePlayers(int playersNum, char playerArray[10][70]);

