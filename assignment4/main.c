
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "functions.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

char playerArray[10][70];
//struct slot sortedSlots[10], slots[10], *slotpoint[10], *sortedSlotP[10];

void readNonExistingFile_testcase() { // test reading a players text file that doesnt exist
	CU_ASSERT_EQUAL(readFile("files/doesntExist.txt", playerArray), -1);
}

void readEmptyFile_testcase() { // test reading an empty players text file
	CU_ASSERT_EQUAL(readFile("files/emptyFile.txt", playerArray), 0);
}

void readTenFile_testcase() { // test reading a valid players text file
	CU_ASSERT(readFile("files/players.txt", playerArray) > 0);
}

void readElevenPlayer_testcase() {
	CU_ASSERT(readFile("files/players11.txt", playerArray) > 10);
}

void sortZeroPlayers_testcase() { // test when zero is the size of the number of players to sort
	readFile("files/players.txt", playerArray);
	sortPlayers(0, playerArray);

	CU_ASSERT_STRING_EQUAL(playerArray[0], "Ogre    	- Donald\n");
	CU_ASSERT_STRING_EQUAL(playerArray[1], "Elf     	- Liliana\n");
	CU_ASSERT_STRING_EQUAL(playerArray[2], "Human   	- Maciej\n");
	CU_ASSERT_STRING_EQUAL(playerArray[3], "Human   	- Francis\n");
	CU_ASSERT_STRING_EQUAL(playerArray[4], "Elf     	- Anthony\n");
	CU_ASSERT_STRING_EQUAL(playerArray[5], "Ogre    	- George W.\n");
	CU_ASSERT_STRING_EQUAL(playerArray[6], "Wizard  	- Massimo\n");
	CU_ASSERT_STRING_EQUAL(playerArray[7], "Ogre    	- Italia\n");
	CU_ASSERT_STRING_EQUAL(playerArray[8], "Ogre    	- Donald T.\n");
	CU_ASSERT_STRING_EQUAL(playerArray[9], "Wizard  	- Evan\n");
}

void sortOnePlayer_testcase() { // test when one is the size of the number of players to sort
	readFile("files/players.txt", playerArray);
	sortPlayers(1, playerArray);

	CU_ASSERT_STRING_EQUAL(playerArray[0], "Ogre    	- Donald\n");
	CU_ASSERT_STRING_EQUAL(playerArray[1], "Elf     	- Liliana\n");
	CU_ASSERT_STRING_EQUAL(playerArray[2], "Human   	- Maciej\n");
	CU_ASSERT_STRING_EQUAL(playerArray[3], "Human   	- Francis\n");
	CU_ASSERT_STRING_EQUAL(playerArray[4], "Elf     	- Anthony\n");
	CU_ASSERT_STRING_EQUAL(playerArray[5], "Ogre    	- George W.\n");
	CU_ASSERT_STRING_EQUAL(playerArray[6], "Wizard  	- Massimo\n");
	CU_ASSERT_STRING_EQUAL(playerArray[7], "Ogre    	- Italia\n");
	CU_ASSERT_STRING_EQUAL(playerArray[8], "Ogre    	- Donald T.\n");
	CU_ASSERT_STRING_EQUAL(playerArray[9], "Wizard  	- Evan\n");
}

void sortTenPlayers_testcase() { // test when 10 is the size of the number of players to sort
	readFile("files/players.txt", playerArray);
	sortPlayers(10, playerArray);

	CU_ASSERT_STRING_EQUAL(playerArray[0], "Elf     	- Anthony\n");
	CU_ASSERT_STRING_EQUAL(playerArray[1], "Elf     	- Liliana\n");
	CU_ASSERT_STRING_EQUAL(playerArray[2], "Human   	- Francis\n");
	CU_ASSERT_STRING_EQUAL(playerArray[3], "Human   	- Maciej\n");
	CU_ASSERT_STRING_EQUAL(playerArray[4], "Ogre    	- George W.\n");
	CU_ASSERT_STRING_EQUAL(playerArray[5], "Ogre    	- Italia\n");
	CU_ASSERT_STRING_EQUAL(playerArray[6], "Ogre    	- Donald\n");
	CU_ASSERT_STRING_EQUAL(playerArray[7], "Ogre    	- Donald T.\n");
	CU_ASSERT_STRING_EQUAL(playerArray[8], "Wizard  	- Evan\n");
	CU_ASSERT_STRING_EQUAL(playerArray[9], "Wizard  	- Massimo\n");
}

void sortLargerSizePlayers_testcase() { // Testing when the size specified in the parameters is larger than the number of players
	readFile("files/players.txt", playerArray);
	sortPlayers(11, playerArray);

	CU_ASSERT_STRING_EQUAL(playerArray[0], "Elf     	- Anthony\n");
	CU_ASSERT_STRING_EQUAL(playerArray[1], "Elf     	- Liliana\n");
	CU_ASSERT_STRING_EQUAL(playerArray[2], "Human   	- Francis\n");
	CU_ASSERT_STRING_EQUAL(playerArray[3], "Human   	- Maciej\n");
	CU_ASSERT_STRING_EQUAL(playerArray[4], "Ogre    	- George W.\n");
	CU_ASSERT_STRING_EQUAL(playerArray[5], "Ogre    	- Italia\n");
	CU_ASSERT_STRING_EQUAL(playerArray[6], "Ogre    	- Donald\n");
	CU_ASSERT_STRING_EQUAL(playerArray[7], "Ogre    	- Donald T.\n");
	CU_ASSERT_STRING_EQUAL(playerArray[8], "Wizard  	- Evan\n");
	CU_ASSERT_STRING_EQUAL(playerArray[9], "Wizard  	- Massimo\n");
}

void sortSmallerSizePlayers_testcase() { // Testing when the size specified in the parameters is smaller than the number of players
	readFile("files/players.txt", playerArray);
	sortPlayers(7, playerArray);

	CU_ASSERT_STRING_EQUAL(playerArray[0], "Elf     	- Anthony\n");
	CU_ASSERT_STRING_EQUAL(playerArray[1], "Elf     	- Liliana\n");
	CU_ASSERT_STRING_EQUAL(playerArray[2], "Human   	- Francis\n");
	CU_ASSERT_STRING_EQUAL(playerArray[3], "Human   	- Maciej\n");
	CU_ASSERT_STRING_EQUAL(playerArray[4], "Ogre    	- George W.\n");
	CU_ASSERT_STRING_EQUAL(playerArray[5], "Ogre    	- Donald\n");
	CU_ASSERT_STRING_EQUAL(playerArray[6], "Wizard  	- Massimo\n");
}

void shuffleZeroPlayers_testcase() {
	readFile("files/players.txt", playerArray);
	shufflePlayers(0, playerArray);

	char expectedPlayer[70] = "Ogre    	- Donald\n"; // the expected player is the first player in

	CU_ASSERT_STRING_EQUAL(playerArray[0], "Ogre    	- Donald\n");
	CU_ASSERT_STRING_EQUAL(playerArray[1], "Elf     	- Liliana\n");
	CU_ASSERT_STRING_EQUAL(playerArray[2], "Human   	- Maciej\n");
	CU_ASSERT_STRING_EQUAL(playerArray[3], "Human   	- Francis\n");
	CU_ASSERT_STRING_EQUAL(playerArray[4], "Elf     	- Anthony\n");
	CU_ASSERT_STRING_EQUAL(playerArray[5], "Ogre    	- George W.\n");
	CU_ASSERT_STRING_EQUAL(playerArray[6], "Wizard  	- Massimo\n");
	CU_ASSERT_STRING_EQUAL(playerArray[7], "Ogre    	- Italia\n");
	CU_ASSERT_STRING_EQUAL(playerArray[8], "Ogre    	- Donald T.\n");
	CU_ASSERT_STRING_EQUAL(playerArray[9], "Wizard  	- Evan\n");
}

void shuffleOnePlayer_testcase() {
	readFile("files/players.txt", playerArray);
	shufflePlayers(0, playerArray);

	CU_ASSERT_STRING_EQUAL(playerArray[0], "Ogre    	- Donald\n");
	CU_ASSERT_STRING_EQUAL(playerArray[1], "Elf     	- Liliana\n");
	CU_ASSERT_STRING_EQUAL(playerArray[2], "Human   	- Maciej\n");
	CU_ASSERT_STRING_EQUAL(playerArray[3], "Human   	- Francis\n");
	CU_ASSERT_STRING_EQUAL(playerArray[4], "Elf     	- Anthony\n");
	CU_ASSERT_STRING_EQUAL(playerArray[5], "Ogre    	- George W.\n");
	CU_ASSERT_STRING_EQUAL(playerArray[6], "Wizard  	- Massimo\n");
	CU_ASSERT_STRING_EQUAL(playerArray[7], "Ogre    	- Italia\n");
	CU_ASSERT_STRING_EQUAL(playerArray[8], "Ogre    	- Donald T.\n");
	CU_ASSERT_STRING_EQUAL(playerArray[9], "Wizard  	- Evan\n");
}

void shuffleTenPlayers_testcase() {
	readFile("files/players.txt", playerArray);
	shufflePlayers(10, playerArray);

	CU_ASSERT_STRING_NOT_EQUAL(playerArray[0], "Ogre    	- Donald\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[1], "Elf     	- Liliana\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[2], "Human   	- Maciej\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[3], "Human   	- Francis\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[4], "Elf     	- Anthony\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[5], "Ogre    	- George W.\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[6], "Wizard  	- Massimo\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[7], "Ogre    	- Italia\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[8], "Ogre    	- Donald T.\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[9], "Wizard  	- Evan\n");
}

void shuffleLargerSizePlayers_testcase() {
	readFile("files/players.txt", playerArray);
	shufflePlayers(11, playerArray);

	CU_ASSERT_STRING_NOT_EQUAL(playerArray[0], "Ogre    	- Donald\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[1], "Elf     	- Liliana\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[2], "Human   	- Maciej\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[3], "Human   	- Francis\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[4], "Elf     	- Anthony\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[5], "Ogre    	- George W.\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[6], "Wizard  	- Massimo\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[7], "Ogre    	- Italia\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[8], "Ogre    	- Donald T.\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[9], "Wizard  	- Evan\n");
}

void shuffleSmallerSizePlayers_testcase() {
	readFile("files/players.txt", playerArray);
	shufflePlayers(7, playerArray);

	CU_ASSERT_STRING_NOT_EQUAL(playerArray[0], "Ogre    	- Donald\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[1], "Elf     	- Liliana\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[2], "Human   	- Maciej\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[3], "Human   	- Francis\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[4], "Elf     	- Anthony\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[5], "Ogre    	- George W.\n");
	CU_ASSERT_STRING_NOT_EQUAL(playerArray[6], "Wizard  	- Massimo\n");
}

void runAllTests(){

	CU_initialize_registry();
	CU_pSuite suiteReadFile = CU_add_suite("readFile_suite", 0, 0);
	CU_pSuite suiteSortPlayers = CU_add_suite("sortPlayers_suite", 0, 0);
	CU_pSuite suiteShufflePlayers = CU_add_suite("shufflePlayers_suite", 0, 0);

	CU_add_test(suiteReadFile, "readNonExistingFile_test", readNonExistingFile_testcase);
	CU_add_test(suiteReadFile, "readEmptyFile_test", readEmptyFile_testcase);
	CU_add_test(suiteReadFile, "readValidFile_test", readTenFile_testcase);
	CU_add_test(suiteReadFile, "readTooManyPlayer_test", readElevenPlayer_testcase);

	CU_add_test(suiteSortPlayers, "sortZeroPlayers_test", sortZeroPlayers_testcase);
	CU_add_test(suiteSortPlayers, "sortOnePlayer_test", sortOnePlayer_testcase);
	CU_add_test(suiteSortPlayers, "sortTenPlayers_test", sortTenPlayers_testcase);
	CU_add_test(suiteSortPlayers, "sortLargerSizePlayers_test", sortLargerSizePlayers_testcase);
	CU_add_test(suiteSortPlayers, "sortSmallerSizePlayers_test", sortSmallerSizePlayers_testcase);

	CU_add_test(suiteShufflePlayers, "shuffleZeroPlayers_test", shuffleZeroPlayers_testcase);
	CU_add_test(suiteShufflePlayers, "shuffleOnePlayer_test", shuffleOnePlayer_testcase);
	CU_add_test(suiteShufflePlayers, "shuffleTenPlayers_test", shuffleTenPlayers_testcase);
	CU_add_test(suiteShufflePlayers, "shuffleLargerSizePlayers_test", shuffleLargerSizePlayers_testcase);
	CU_add_test(suiteShufflePlayers, "shuffleSmallerSizePlayers_test", shuffleSmallerSizePlayers_testcase);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
}

int main() {
    runAllTests();
    return 0;
}

/*
int main(void) {
	//declares the number of players and the number of slots
	int playersNum;

	//reads the players file
	playersNum = readFile(PLAYERS_FILE, playerArray);


	//orders the players
	sortPlayers(playersNum, playerArray);


	//shuffles the players
	shufflePlayers(playersNum, playerArray);

	for(int i =0; i < playersNum; i ++)
		printf ("%s\n", playerArray[i]);

	return 0;
}

*/
