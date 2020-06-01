/******************************************************
	67. Add Binary
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.

******************************************************/
//Point to note: When dyn allocating memory for strings, to copy from one string to another, always account for NULL at the end 
//and add 1 more byte , which is why i have done size+2 here.
char* append_zeroes(char* p,int size){
    char* new_arr=(char*)malloc(size);
    memset(new_arr,'0',size);
    
    memcpy(new_arr+size-strlen(p),p,strlen(p));
    
    return new_arr;
}

bool addB(char* a,char* b,int size){
    
    bool carry=0;
    
    for(int i=size-1;i>=0;i--){
        if(a[i]=='1' && b[i]=='1'){
            if(carry){
                a[i]='1';carry=1;
            }
            else{
                a[i]='0';carry=1;
            }
        }
        else if(a[i]=='1' && b[i]=='0'){
            if(carry){
                a[i]='0';carry=1;
            }
            else{
                a[i]='1';carry=0;
            }
        } 
        else if(a[i]=='0' && b[i]=='1') {
            if(carry){
                a[i]='0';carry=1;
            }
            else{
                a[i]='1';carry=0;
            }
        }
        else {
            if(carry){
                a[i]='1';carry=0;
            }
            else{
                a[i]='0';carry=0;
            }
        }
    }
    return carry;
}

char * addBinary(char * a, char * b){
    if(strlen(a)<strlen(b)){
        
        a=append_zeroes(a,strlen(b));
        
        bool carry = addB(a,b,strlen(b));
        int size=strlen(b);
        
        if(carry){
            char* ret_arr=(char*) calloc((size+2),sizeof(char));
            memcpy(ret_arr+1, a, size);
            *ret_arr='1';
            return ret_arr;
        }
        char* ret_arr=(char*) calloc((size+1),sizeof(char));
        memcpy(ret_arr, a, size);
        return ret_arr;
    }
    else if(strlen(a)>strlen(b)){
        b=append_zeroes(b,strlen(a));
        
        bool carry = addB(a,b,strlen(a));
        
        int size=strlen(a);
        
        if(carry){
            char* ret_arr=(char*) calloc((size+2),sizeof(char));
            memcpy(ret_arr+1, a, size);
            *ret_arr='1';
            return ret_arr;
        }
        char* ret_arr=(char*) calloc((size+1),sizeof(char));
        memcpy(ret_arr, a, size);
        return ret_arr;
    }
    
    bool carry = addB(a,b,strlen(a)); 
    int size=strlen(a);
        
    if(carry){
        char* ret_arr=(char*) calloc((size+2),sizeof(char));
        memcpy(ret_arr+1, a, size);
        *ret_arr='1';
        return ret_arr;
    }
    char* ret_arr=(char*) calloc((size+1),sizeof(char));
    memcpy(ret_arr, a, size);
    return ret_arr;
}
