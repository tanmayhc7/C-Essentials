/**************************************
32. Longest Valid Parentheses

Given a string containing just the characters '(' and ')', 
find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
****************************************/

/******************************
1) Create an empty stack and push -1 to it. The first element
   of the stack is used to provide a base for the next valid string. 

2) Initialize result as 0.

3) If the character is '(' i.e. str[i] == '('), push index 
   'i' to the stack. 
   
2) Else (if the character is ')')
   a) Pop an item from the stack (Most of the time an opening bracket)
   b) If the stack is not empty, then find the length of current valid
      substring by taking the difference between the current index and
      top of the stack. If current length is more than the result,
      then update the result.
   c) If the stack is empty, push the current index as a base for the next
      valid substring.

3) Return result.
******************************/

int longestValidParentheses(char * S){
    if(!S || strlen(S)==0)return 0;
    int* stack=(int*)calloc(strlen(S)+1,sizeof(int));
    int top=-1;
    stack[++top]=-1;
    int ret=0;
    
    for(int i=0;i<strlen(S);i++){
        if(S[i]=='('){
            stack[++top]=i;        
        } else{
            top--;
            if(top>=0) {
                ret = ret > (i-stack[top]) ? ret : (i-stack[top]);
            } else{
                stack[++top]=i;        
            }
        }
                
    }
    free(stack);
    return ret;
}
