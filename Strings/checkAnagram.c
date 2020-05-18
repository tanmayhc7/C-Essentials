/*
 * checkAnagram.c
 *
 *  Created on: Nov 16, 2019
 */
/** To check if the two strings are anagrams.**/
int Anagram(char *str1, char *str2)// two input strings str1 and str2
{
	// initialize two arrays count 1 and count 2 to zero to count the characters in the strings
	int count1[26] = {0}, count2[26] = {0};

   /* if String size is not equal */
   if(strlen(str1) != strlen(str2))
   {
	   return 0;
   }

   for(int i=0;i<strlen(str1);i++)//iterating through the string to calculate the number of characters in string1
   {
      count1[str1[i] - 'a']++;
   }
   for(int i=0;i<strlen(str2);i++)//iterating through the string to calculate the number of characters in string2
   {
      count2[str2[i] - 'a']++;
   }
   for (int i = 0; i < 26; i++)
    {
        if (count1[i] != count2[i])// condition to check if the number of characters are equal in two strings.
            return 0;
    }
    return 1;
}



