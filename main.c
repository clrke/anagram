#include <stdio.h>
#include "anagram.h"

int main(int argc, char const *argv[])
{
	char retry[1];
	char word1[50], word2[50];
	do
	{
		printf("\n");

		printf("Enter first word: ");
		gets(word1);

		printf("Enter second word: ");
		gets(word2);

		printf("Output: ");
		if(anagram(word1, word2))
			printf("Anagram!\n\n");
		else
			printf("Not Anagram!\n\n");

		printf("Enter another? [y/n]: ");

		gets(retry);

	} while(tolower(retry[0]) == 'y');

	return 0;
}
