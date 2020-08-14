/****************************
205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
****************************/
//HAve 2 char arrays and map char of s to arr-T and vice versa and if they dont overlap return false
bool isIsomorphic(char * s, char * t){
    char arr_s[256]={0};
    char arr_t[256]={0};
    
    int i=0;
    while(i<strlen(s)){
        if(arr_s[s[i]]==0 && arr_t[t[i]]==0){
            arr_s[s[i]]=t[i];
            arr_t[t[i]]=s[i];
        }
        else{
            if(arr_s[s[i]]!=t[i] || arr_t[t[i]]!=s[i])
                return false;
        }
        i++;
    }
    return true;
}
