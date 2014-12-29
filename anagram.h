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
