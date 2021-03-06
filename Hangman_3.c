/*
Hangman ver 1.0
David Noone
10. Oct. 2018
*/

#include "pch.h" /* precompiled header for visual studio*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

#define MAXWORD 100
#define GUESSES 8

void Welcome();
char* Enterword();
void Printblanks(char word[], int length);
void Userguess(char word[], int length);
void Displayman(int wrongtries);
int CheckWinner(char word[], char inputword[], int length);

int main() {

	char mainWord[MAXWORD];
	int lengthWord;

	Welcome();
	strcpy(mainWord, Enterword());
	lengthWord = strlen(mainWord);

	Printblanks(mainWord, lengthWord);
	Userguess(mainWord, lengthWord);

	return 0;
}

void Welcome() {

	system("cls");
	printf("\n Welcome to Hangman! \n ");
	printf("\n In this game, player 1 enters a word and player 2 has to guess it! \n ");
	printf("\n Player 2 gets 8 wrong tries before losing the game. \n ");
	printf("\n Enter any key to begin: \n ");
	getchar();
	system("cls");
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
	system("cls");
	printf("\nPlayer 2: \n");
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

	char wordOutput[MAXWORD];
	int wrongTry = GUESSES, matchFound = 0, i, wrong= 0;
	char letterGuess;


	for (int i = 0; i < length; i++) {

		if (word[i] == ' ') {
			wordOutput[i] = ' ';

		}
		else {
			wordOutput[i] = '_';
		}
	}
	wordOutput[length] = '\0';

	while (wrongTry != 0) { /* while loop runs until game is over*/
		printf("\nGuess a letter: ");
		
		
		letterGuess = toupper(getc(stdin));

		if (letterGuess == '\n') { /* Removes newline character */
			letterGuess = toupper(getc(stdin));
		}

		if(letterGuess >= 'A' && letterGuess <= 'Z') {
			matchFound = 0;
		}
		else {
			matchFound = 2;
		
		}/* End of check if user input is correct*/
		
		if (matchFound == 2) {
			printf("\nYou have entered an incorrect character. Please try again.");
		} /*End of print incorrect prompt*/

		if (matchFound != 2) {
			for (i = 0; i < length; i++) {

				if (letterGuess == word[i]) {

					wordOutput[i] = word[i];
					matchFound = 1;
				}
				else {

					wrong = 1;

				}/* end of user guesses letter */
				printf("%c", wordOutput[i]);
			}
			if (matchFound == 1) {
				printf("\nYou guessed a letter! Good job!\n");
				printf("\nYou have %d incorrect tries remaining.\n", wrongTry);
				wrong = 0;

				
				if (CheckWinner(word, wordOutput, length) == 1) {
					
					printf("\nYou have won!\n\n\n");
					break;
				
				}

			}
			else if (wrong == 1) {
				wrongTry--;
				printf("\n%c is not a letter in the word.", letterGuess);
				Displayman(GUESSES - wrongTry);
				printf("\nYou have %d incorrect tries remaining.\n", wrongTry);
			}
		} /* End of checker if matchFound != 2 */

		
	} /* End of while loop: checks if there are trys left */


	
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
		printf("You have lost!");
		break;
	}

}

int CheckWinner(char word[], char inputword[], int length) {
	
	int match = 0;
	
	if (strcmp(word, inputword) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
