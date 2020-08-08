/*******************************

680. Valid Palindrome II
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
********************************/

bool isPal(char* s,int i,int j){
      while(i<j)
    {
        if(s[i]!=s[j])
            return 0;
        i++;j--;
    }
    return 1;
}

bool validPalindrome(char * s){
    for(int i=0,j=strlen(s)-1;i<j;){
        if(s[i]!=s[j]){
            return isPal(s,i+1,j) || isPal(s,i,j-1);//send part of substring (if char are same then substrings must also be palindromes
        }
        i++;j--;
    }
    return 1;
}
