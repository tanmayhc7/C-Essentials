/****************************************************************
1160. Find Words That Can Be Formed by Characters

You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

 

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: 
The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: 
The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 

Note:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
All strings contain lowercase English letters only.


*****************************************************************/

int countCharacters(char ** words, int wordsSize, char * chars){
    
    //create a map for tracing each letter in chars & words
    int char_map[26]={0};
    int word_map[26]={0};
    
    //populate char_map
    for(int i=0;i<strlen(chars);i++){
        char_map[chars[i]-'a']++;
    }
    
    int backup;
    int sum=0;
    bool flag=1;
    
    //traverse through each word and populate words map and compare
    for(int i=0;i<wordsSize;i++){
        for(int j=0;words[i][j]!='\0';j++){
            word_map[words[i][j]-'a']++;
        }
        for(int k=0;k<26;k++){
            if(word_map[k]>char_map[k]){
                flag=0; break;
            }
        }
        
        if(flag){
            sum+=strlen(words[i]);
        }
        flag=1;
        memset(word_map,0,26*sizeof(int));
    }
    
    return sum;
}
