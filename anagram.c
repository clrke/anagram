#include <stdio.h>
#include <string.h>

// boolean
#define true 1
#define false 0

char tolower(char c) {
	if(c >= 'A' && c <= 'Z')
		return c+32; // plus 32 because ASCII value of 'A' is 65 and 'a' is 97
	else
		return c;
}

int anagram(char word1[50], char word2[50]) {
	int i, j;
	int word1_len = strlen(word1);
	int word2_len = strlen(word2);

	for (i = 0; i < word1_len; i++)
		if(word1[i] != ' ')
		{
			// hanapin yung letter kung meron sa word2
			int letter_found = false;
			for (j = 0; j < word2_len; j++)
			{
				// tolower para letter 'A' is equal to 'a'
				if(tolower(word1[i]) == tolower(word2[j]))
				{
					word2[j] = ' ';
					letter_found = true;
					break;
				}
			}
			if( ! letter_found)
				return false;
		}

	// tignan kung may natirang letter sa word2 na wala sa word1
	for (j = 0; j < word2_len; j++)
		if(word2[j] != ' ')
			return false;

	return true;
}

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
