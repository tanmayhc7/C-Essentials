/*
 * reverseString.c
 *
 *  Created on: Nov 16, 2019
 */

void reverse_str(char *s)
{
    const int len = strlen(s);
    const int mid = len / 2;
    for (int i = 0, j=len-1; i < mid; i++, j--) {
        char c = s[i];
        s[i]   = s[j];
        s[j]   = c;
    }
}



