/*********************************
	242. Valid Anagram
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.
*********************************/

//Method 1: Alphabet Dictionary
bool isAnagram(char * s, char * p){
    
    if(!(strlen(s) && strlen(p))) return 1;
    
    if(!strlen(s) || !strlen(p) || (strlen(p)!=strlen(s))) {
        return 0;
    }
    
    int num1[26]={0};
    int num2[26]={0};
 
    for(int i=0;s[i] != '\0';i++)
    {
        num1[s[i] - 'a']++;
    }
    
    for(int i=0;p[i] != '\0';i++)
    {
        num2[p[i] - 'a']++;
    }    
    
   for (int i = 0; i < 26; i++)
    {
        if (num1[i] != num2[i])
            return 0;
    }
    return 1;    
}

// Method 2: Sorting (Time limit exceeds for large strings)
void sort_string(char* s){
    bool swapped;
    for(int i=0;i<strlen(s);i++){
       swapped=0;
        for(int j=0;j<strlen(s)-i-1;j++){
            if(s[j]>s[j+1]){
                char temp= s[j]; s[j]=s[j+1]; s[j+1]=temp;
                swapped=1;
            }
        }
        if(!swapped) break;
    }
}


bool isAnagram(char * s, char * p){
    
    if(!(strlen(s) && strlen(p))) {
        printf("1");
        return 1;
    }
    
    if(!strlen(s) || !strlen(p) || (strlen(p)!=strlen(s))) {
        return 0;
    }
    
    if(!(strlen(s)==1 && strlen(p)==1)) {
        sort_string(s);
        sort_string(p);
    }
    
    if(strcmp(s,p)==0) return 1;
    return 0;
}

