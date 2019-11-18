/*
 ============================================================================
 Name        : Strings.c
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "myString.h"

int main(void) {
	char s1[38]="I'll do YOU one better! WHY is Gamora?";
	char* str=s1;
	printf("%s",s1);
	/*---------------*/

	char* last=last_word_in_string(str);
	printf("\nLast Word in String: %s",last);

	/*---------------*/

	reverse_str(str);
	printf("\nReversed String: %s",s1);
	reverse_str(str);

	/*---------------*/

	reverse_words_in_string(str);
	printf("\nReversed Words in String: %s",s1);

	/*---------------*/
	char s2[5]="Love you 3000!!";
	char* str2=s2;
	printf("\nString to int: %d",string_to_int(str2));

	/*---------------*/

	char s3[100]="ballytrewqqwerty";
	char* str3=s3;
	char s4[100]="alblqwertyytrewq";
	char* str4=s4;
	printf("\n%s and %s %s ",s3,s4,(Anagram(str3,str4)?"are Anagrams":"are not Anagrams"));

	/*---------------*/

	string_Lib();

	/*---------------*/

	reverse_every_word();

	/*---------------*/
	char str1[] = "ABC";
	int n = strlen(str1);
	permute(str1, 0, n-1);

	/*---------------*/
	check_substring_occurrences();

	/*---------------*/
	void check_freq_of_every_word();

	/*---------------*/
    char new_str2[50]="computer";
	char new_str1[50]="programming";
    int a1[26] = {0};
    char str2_rem[50];
    alphacheck(new_str1, a1);
    create(str2_rem, new_str2, a1);
    printf("On removing characters from second string we get: %s\n", str2_rem);

	return 0;
}
