/*
Hangman ver 0.1
David Noone
03. Oct. 2018
*/

#include "pch.h" /* precompiled header for visual studio*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

#define MAXWORD 100
#define GUESSES 8

char* Enterword();
void Printblanks(char word[], int length);
void Userguess(char word[], int length);
void Displayman(int wrongtries);

int main() {

	char mainWord[MAXWORD];
	int lengthWord;

	system("cls");
	strcpy(mainWord, Enterword());
	lengthWord = strlen(mainWord);

	system("cls");
	Printblanks(mainWord, lengthWord);
	Userguess(mainWord, lengthWord);

	return 0;
}

/* Enter the desired word here*/
char* Enterword() {

	char playerWord[MAXWORD];
	printf("\n\nPlayer 1, enter the word here: ");
	fgets(playerWord, MAXWORD, stdin);
	strtok(playerWord, "\n");   /* Eliminates trailing \n */
	char * s = playerWord;

	while (*s) {
		*s = toupper((unsigned char)*s);
		s++;
	}
	return playerWord; /* Converts all characters to uppercase */
}

/* Outputs a series of blank characters for each non-space character in the string*/
void Printblanks(char word[], int length) {

	char blankchars[MAXWORD];
	printf("\n\nHere is the word you need to solve:\n\n");
	printf("NOTE: the total length is : %d characters long \n\n", length);

	for (int i = 0; i < length; i++) {

		if (word[i] == ' ') {
			blankchars[i] = ' ';

		}
		else {
			blankchars[i] = '_';
		}
		printf("%c", blankchars[i]);
	}
}

/* Big checker function to run each of the users turns until the word is guessed or they lose */
void Userguess(char word[], int length) {

	char wordOutput[MAXWORD], temp[MAXWORD];
	int wrongTry = GUESSES, matchFound = 0, i, j, position = 0, winner;
	char letterGuess;

	system("cls");


	while (wrongTry != 0) { /* while loop runs until game is over*/
		printf("\nGuess a letter: ");
		
		letterGuess = toupper(getc(stdin));
		printf("%c", letterGuess);

		if(letterGuess > 'A' && letterGuess < 'Z') {
			matchFound = 0;
		}
		else {
			matchFound = 2;
		
		}/* End of check if user input is correct*/
		
		if (matchFound == 2) {
			printf("\nYou have entered an incorrect character. Please try again.");
		} /* End of print incorrect prompt*/

		for (i = 0; i < length; i++) {
		
		}
		getchar();






	} /* End of while loop: checks if matchFound != 2 */
	


	
} /* End of checker function*/



void Displayman(int wrongtries) {

	switch (wrongtries) {

	case 1:
		printf("\n\n\n\n\n\n\n");
		printf("                _______________");
		printf("\n");
		break;

	case 2:
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("                ________|_______");
		printf("\n");
		break;

	case 3:
		printf("\n");
		printf("\t\t         ______");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("                ________|_______");
		printf("\n");
		break;

	case 4:
		printf("\n");
		printf("\t\t         ______");
		printf("\n");
		printf("\t\t\t|      |");
		printf("\n");
		printf("\t\t\t|      |");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("                ________|_______");
		printf("\n");
		break;

	case 5:
		printf("\n");
		printf("\t\t         ______");
		printf("\n");
		printf("\t\t\t|      |");
		printf("\n");
		printf("\t\t\t|      |");
		printf("\n");
		printf("\t\t\t|      O");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("                ________|_______");
		printf("\n");
		break;

	case 6:
		printf("\n");
		printf("\t\t         ______");
		printf("\n");
		printf("\t\t\t|      |");
		printf("\n");
		printf("\t\t\t|      |");
		printf("\n");
		printf("\t\t\t|      O");
		printf("\n");
		printf("\t\t\t|      |");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("                ________|_______");
		printf("\n");
		break;

	case 7:
		printf("\n");
		printf("\t\t         ______");
		printf("\n");
		printf("\t\t\t|      |");
		printf("\n");
		printf("\t\t\t|      |");
		printf("\n");
		printf("\t\t\t|      O");
		printf("\n");
		printf("\t\t\t|    --|--");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("                ________|_______");
		printf("\n");
		break;

	case 8:
		printf("\n");
		printf("\t\t         ______");
		printf("\n");
		printf("\t\t\t|      |");
		printf("\n");
		printf("\t\t\t|      |");
		printf("\n");
		printf("\t\t\t|      O");
		printf("\n");
		printf("\t\t\t|    --|--");
		printf("\n");
		printf("\t\t\t|     / \\");
		printf("\n");
		printf("\t\t\t|");
		printf("\n");
		printf("                ________|_______");
		printf("\n");
		break;
	}

}
