/**************************************
921. Minimum Add to Make Parentheses Valid

Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

Example 1:

Input: "())"
Output: 1
Example 2:

Input: "((("
Output: 3
Example 3:

Input: "()"
Output: 0
Example 4:

Input: "()))(("
Output: 4
 

Note:

S.length <= 1000
S only consists of '(' and ')' characters.
********************************************************/
int minAddToMakeValid(char * S){
    if(!S || strlen(S)==0)return 0;
    char* stack=(char*)calloc(1001,sizeof(char));
    int top=-1;
    stack[++top]=S[0];
    int size=1;
    for(int i=1;i<strlen(S);i++){
        if(top>=0){
            if(stack[top]=='('){
                if(S[i]==')'){
                    top--;
                    size--;
                    continue;
                } 
            }    
        }
        stack[++top]=S[i];
        size++;
        
    }
    free(stack);
    return size;
}
