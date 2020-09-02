/************************************
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
************************************************/
bool isValid(char* S) {
    char* stack=(char*)calloc(10000,sizeof(char));
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
            } else if(stack[top]=='{'){
                if(S[i]=='}'){
                    top--;
                    size--;
                    continue;
                } 
            } else if(stack[top]=='['){
                if(S[i]==']'){
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
    return (top == -1);
}
