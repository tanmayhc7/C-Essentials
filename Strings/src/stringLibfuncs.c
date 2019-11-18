/*
 * stringLibfuncs.c
 *
 *  Created on: Nov 16, 2019
 */
void string_Lib()
{
	char str1[12] = "Hello";
	char str2[12] = "World";
	char str3[12];
	int  len ;
	//Copy string 1 to string 3
	strcpy(str3, str1);
	printf("\nstrcpy( str3, str1) :  %s\n", str3 );
	//Concatenate string 1 and string 2
	strcat( str1, str2);
	printf("strcat( str1, str2):   %s\n", str1 );
	//Total Length of string 1 after concatenation
	len = strlen(str1);
	printf("strlen(str1) :  %d\n", len );
	/*-------------------------------------------------------------*/
	//Copy first n characters of string 2 to string 1 (Here we have used function memset() to clear the memory location)
	char src[40];
	char dest[12];
	memset(dest, '\0', sizeof(dest));
	strcpy(src, "Wakanda Forever");
	strncpy(dest, src, 10);
	printf("Final copied string - %s\n", dest);
	/*--------------------------------------------------------------*/
	//Compare string1 and string2 to determine alphabetic order
	int ret;

	strcpy(str1, "abcdef");
	strcpy(str2, "ABCDEF");

	ret = strcmp(str1, str2);

	if(ret < 0)
	{
	  printf("str1 is less than str2");
	}
	else if(ret > 0)
	{
	  printf("str2 is less than str1");
	}
	else
	{
	  printf("str1 is equal to str2");
	}
	/*--------------------------------------------------------------*/
	//First occurrence of the character c in the string str
	const char str[] = "http://www.abc.com";
	const char ch = '.';

	ret= strchr(str, ch);

	printf("String after |%c| is - |%s|\n", ch, ret);
	/*--------------------------------------------------------------*/
	//Last occurence of character c in string.
	ret = strrchr(str, ch);
	printf("String after |%c| is - |%s|\n", ch, ret);
	/*--------------------------------------------------------------*/
	const char haystack[20] = "HelloWorld";
	const char needle[10] = "World";
	ret = strstr(haystack, needle);
	printf("The substring is: %s\n", ret);
}




