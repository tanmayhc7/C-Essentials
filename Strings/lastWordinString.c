/*
 * lastWordinString.c
 *
 *  Created on: Nov 16, 2019
 */
char* last_word_in_string(char *s)
{
	int i=0;
	char* last;
	const int len= strlen(s) -1;
	char *j = s + len;
/* If last letter of string is blank space then it will be avoided */
	if (*(s+len) == ' ')
	{
		j = j-1;
	}
	while(*j)
	{

		if ( *j== ' ')
		{
			j++;
			break;
		}
		j--;
		i++;

	}
	return j;
}



