/*
 *

A valid parentheses string is either empty (""), "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.  For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.

A valid parentheses string S is primitive if it is nonempty, and there does not exist a way to split it into S = A+B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string S, consider its primitive decomposition: S = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings.

Return S after removing the outermost parentheses of every primitive string in the primitive decomposition of S.
*/
char * removeOuterParentheses(char * S)
{
    int size=strlen(S);
    char* R=malloc(size*sizeof(char));
    int k=0;
    int p=0;
    for(int i=1;i<size;i++)
    {
        if(S[i]=='(')
        {
            p++;
        }
        else
        {
            p--;
        }
        if (p>=0)
        {
            R[k++]=S[i];
        }
        else
        {
            p=0;i++;
        }
    }
    R[k]='\0';
    return R;
}

