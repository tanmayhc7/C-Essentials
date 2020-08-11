/************************************
168. Excel Sheet Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
Example 1:

Input: 1
Output: "A"
Example 2:

Input: 28
Output: "AB"
Example 3:

Input: 701
Output: "ZY"
****************************************/

char * convertToTitle(int n){
    char *str=(char*)malloc(8);
    str[7]='\0';
    int i=6;
    int rem;
    
    while(n>0){
        rem=n%26;
        if(rem==0) {
            n-=26;
            rem=26;
        }
        str[i--]='A'+rem-1;   
        n=n/26;
    }
    //printf("%s",res);
    return str+i+1;
}
