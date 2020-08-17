/*******************************
1047. Remove All Adjacent Duplicates In String

Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.

 

Example 1:

Input: "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
 

Note:

1 <= S.length <= 20000
S consists only of English lowercase letters.
*******************************/

char * removeDuplicates(char * S){
    char *stack=(char*)malloc(strlen(S)*sizeof(char));
    int size=0;
    int top=-1;
    
    for(int i=0;i<strlen(S);i++){
        if(top<0){
            stack[++top]=S[i];
            size++;
        }else{
            if(stack[top]==S[i]){
                top--;
                size--;
            }else{
                stack[++top]=S[i];
                size++;
            }
        }
    }
    
    if(top<0) {
        char *ret=(char*)malloc(1);    
        ret[0]='\0';
        free(stack);
        return ret;
    }
    
    char *ret=(char*)malloc((size+1)*sizeof(char));
    for(int i=size-1;i>=0;i--){
        ret[i]=stack[top--];
    }
    ret[size]='\0';
    free(stack);
    return ret;
    
}
