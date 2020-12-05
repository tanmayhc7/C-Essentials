/****************************************
5. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Example 3:
Input: s = "a"
Output: "a"

Example 4:
Input: s = "ac"
Output: "a"

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case)
****************************************/
char * longestPalindrome(char * s){
    int max=1;
    char* p=s;
    char* subStart=s;
    char* start=s,*end=s;
    
    while(*p){
        start=p; end=p;
 
        while(*(end+1) && *(end+1)==*end){
            end++;
        }
 
        p=end+1;
        
        while(*(end+1) && (start>s) && *(end+1)==*(start-1)){
            start--;
            end++;
        }
        
        if(end-start+1 > max){
            max=end-start+1;
            subStart=start;
        }
    }
    
    char* ret=(char*)malloc(max+1);
    ret[max]='\0';
    memcpy(ret,subStart,max);
    return ret;
}
