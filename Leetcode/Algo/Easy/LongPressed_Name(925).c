/***********************************************
925. Long Pressed Name
Your friend is typing his name into a keyboard.  Sometimes, when typing a character c, the key might get long pressed, and the character will be typed 1 or more times.

You examine the typed characters of the keyboard.  Return True if it is possible that it was your friends name, with some characters (possibly none) being long pressed.

Example 1:

Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
Example 2:

Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
Example 3:

Input: name = "leelee", typed = "lleeelee"
Output: true
Example 4:

Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.
 

Constraints:

1 <= name.length <= 1000
1 <= typed.length <= 1000
The characters of name and typed are lowercase letters.
************************************************/
bool isLongPressedName(char * name, char * typed){
    
    if(strlen(name)>strlen(typed)) return 0;
    
    int cur_count_n=0;
    int cur_count_t=0;
    char cur_char_n=name[0];
    char cur_char_t=typed[0]; 
    int n=1,t=1;
    for(;n<strlen(name),t<strlen(typed);){
        if(cur_char_n == cur_char_t){
            while(name[n]==cur_char_n){
                cur_count_n++;n++;
            }
            while(typed[t]==cur_char_t){
                cur_count_t++;t++;
            }
            if(cur_count_n > cur_count_t) return 0;
            
            cur_count_n=0;cur_count_t=0;
            if(n<strlen(name)) cur_char_n=name[n];
            if(t<strlen(typed)) cur_char_t=typed[t];
        }
        else{ return 0;}
    }
    
    if(n<strlen(name) && t>=strlen(typed)) return 0;
    
    return 1;
}

