/***********************************
	438. Find All Anagrams in a String

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
***********************************/

//Using the Sliding window Technique

void form_p_arr(char* p,int *num2){
    int i=0;
    while (p[i] != '\0')
    {
        num2[p[i] -'a']++;
        i++;
    }
}

bool check_anagram(char* s,int window_size,int *num2){
 
    int num1[26]={0};
 
    for(int i=0;i < window_size;i++)
    {
        num1[s[i] - 'a']++;
    }
    
   for (int i = 0; i < 26; i++)
    {
        if (num1[i] != num2[i])
            return 0;
    }
    return 1;    
}


int* findAnagrams(char* s, char* p, int* returnSize){
    
    if(!strlen(s) || !strlen(p) || (strlen(p)>strlen(s))) {
        *returnSize=0;
        return NULL;
    }
    
    int num2[26]={0};
    form_p_arr(p,num2);
    *returnSize=0;
    
    int *ret_arr=(int*)malloc(strlen(s)*sizeof(int));
    memset(ret_arr,0,strlen(s));
    int ret_size=0;
    for(int j=0;j<=strlen(s)-strlen(p);j++){
        if(check_anagram(s+j,strlen(p),num2)){
            ret_arr[ret_size++]=j;
        }
    }
    *returnSize=ret_size;
    return ret_arr;
}
