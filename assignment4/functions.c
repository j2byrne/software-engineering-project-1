/*
 * functions.c

 *
 *  Created on: 24 Apr 2017
 *      Author: liliana
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "functions.h"

/* This function reads a file and populates playerArray
 * (each row contains a line of the file being read).
 * The function returns the number of players.
 *
 * Input Parameters
 * 	filePath: the file URL
 * 	playerArray: the array being populated with the payers information
 *
 */
int readFile(char * filePath, char playerArray[10][70]){
	int lineNum = 0;
	FILE *fp = fopen(filePath,  "r+" );  /* open for reading */
	if (fp == NULL ){      /* check does weather file exist etc */
		perror ("Error opening players file");
		return -1;
	} else {
	// fgets returns NULL when it gets to the end of the file
		while( fgets( playerArray[lineNum], sizeof(playerArray[lineNum]), fp ) != NULL )
			lineNum++;
	}
	fclose (fp);
	return lineNum;
}


/*
 * This function sorts the players provided as input alphabetically using the
 * insertion sort algorithm
 *
 * Input Parameters
 * 	playersNum: the number of players
 * 	playerArray: the array of strings containing the players information to be ordered.
 *
 */
void sortPlayers(int playersNum, char playerArray[10][70]){
	char temp[70];
	int j;
	for(int i=0; i < playersNum; i++){
		j= i;
		//pairwise comparison
		while(j > 0 && strcmp(playerArray[j],playerArray[j-1])< 0){
			//swapping elements
			strcpy(temp,playerArray[j]);
			strcpy(playerArray[j],playerArray[j-1]);
			strcpy(playerArray[j-1],temp);
		}
	}
}


/*
 * This function shuffles the players provided as input using the
 * Fisher Yates algorithm
 *
 * Input Parameters
 * 	playersNum: the number of players
 * 	playerArray: the array of strings containing the players information to be ordered.
 *
 */
void shufflePlayers(int playersNum, char playerArray[10][70]) {
	char temp[70];
	printf("Shuffle");
	int index;
	srand(time(NULL));	//seed initialisation for function rand
	for(int i=1; i< playersNum; i++){
		// index to be swapped with the element at index i
		index = rand() % i ;
		//swap
		strcpy(temp,playerArray[index]);
		strcpy(playerArray[index],playerArray[i]);
		strcpy(playerArray[index],temp);
	}
}



	//	lineNum = 0;
	//	fp = fopen(SLOTS_FILE_PATH,  "r+" );       /* open for reading */
	//	if (fp == NULL ){      /* check does weather file exist etc */
	//	perror ("Error opening weather file");
	//			lineNum = -1; /* use this as a file not found code */
	//	} else {
		// fgets returns NULL when it gets to the end of the file
	//		while ( fgets( slotArr[lineNum], sizeof(slotArr[lineNum]), fp ) != NULL ) {
	//				lineNum++;
	//		}
	//		fclose (fp);
	//	}
