/**************************************************
	917. Reverse Only Letters

Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, 
and all letters reverse their positions.

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"

*************************************************/

bool is_symbol(char c){
    if( (c>=33 && c<=64) || (c>=91 && c<=96)){
        return true;
    }
    return false;
}

void swap(char* a, char* b){
    char temp=*a;
    *a=*b;
    *b=temp;
}

char * reverseOnlyLetters(char * S){
    for(int i=0,j=strlen(S)-1;i<j;){
        if(!is_symbol(S[i]) && !is_symbol(S[j])){
            swap(&S[i],&S[j]);
            i++;j--;
        }
        else if(is_symbol(S[i]) && !is_symbol(S[j])){
            i++;
        } 
        else if(!is_symbol(S[i]) && is_symbol(S[j])){
            j--;
        }
        else{
            i++;j--;
        }
    }
    return S;
}
