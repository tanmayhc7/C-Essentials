/*
 * reverseWordsinaString.c
 *
 *  Created on: Nov 16, 2019
 */

void reverse_words_in_string(char *s)
{
	/*
	 * 1st step
	 * In below while loop , string becomes "erehw ereht si a lliw ereht si a yaw"
	 */
	/* To obtain the start of word to be reversed in a string and its length */
	int i=0;
	/*To traverse through string */
	unsigned int j=0;

	while(j <= strlen(s))
	{
		/* Check for word in string. '\0' condition is checked for last word */
		if( *(s+j) == ' ' || *(s+j) == '\0')
		{
			/* (s+i) points at the start of word and (j-i) denotes the length */
			reverse( s+i, j-i );
			/* "i" will have the index at which next word starts */
			i = j+1;
		}
		j++;
	}
	/*
	 * 2nd Step
	 * string "erehw ereht si a lliw ereht si a yaw" is reversed to get "way a is there will a is there where"
	 */
	reverse(s,strlen(s));

}


void reverse(char *s ,int len)
{
    int i,j;
	char temp;
	j= len - 1;
	int mid = len/2;
	for(i=0;i<mid;i++,j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;

	}
}
