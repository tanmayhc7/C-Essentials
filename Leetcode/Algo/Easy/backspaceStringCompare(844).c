/************************************************
844. Backspace String Compare

Given two strings S and T, return if they are equal when both are typed into empty text editors. 
# means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:
Can you solve it in O(N) time and O(1) space?
***********************************************/

bool backspaceCompare(char * S, char * T){
    int i = strlen(S)-1;
    int j = strlen(T)-1;

    int countS = 0, countT = 0;

    //any i or j should be considered
    while (i >= 0 || j >= 0) {
        //# +1, other but has remaining # -1, note --i
        while (i >= 0 && (S[i] == '#' || countS > 0)) 
            countS += S[i--] == '#' ? +1 : -1;
        
        while (j >= 0 && (T[j] == '#' || countT > 0))
            countT += T[j--] == '#' ? +1 : -1;
        
        //i and j could be negative
        if (i < 0 || j < 0)
            return i == j;//possibly true if i == j
        
        if (S[i--] != T[j--])
            return false;
    }
    
    return i == j;
}
