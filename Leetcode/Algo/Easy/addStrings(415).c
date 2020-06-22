/****************************************
	415. Add Strings
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
****************************************/
char* append_zeroes(char* p,int size){
    char* new_arr=(char*)malloc(size);
    memset(new_arr,'0',size);
    
    memcpy(new_arr+size-strlen(p),p,strlen(p));
    
    return new_arr;
}

bool addNums(char* num1, char* num2, int size){
    int carry=0; int sum=0;
    for(int i=size-1;i>=0;i--){
        sum=(num1[i]-'0')+(num2[i]-'0')+carry;
        if(sum>=10){
            carry=1;
            sum=sum-10;
        }
        else{
            carry=0;
        }
        num1[i]=sum+48;
    }
    return carry;
}


char * addStrings(char * num1, char * num2){
    
    if(strlen(num1) < strlen(num2)){
        
        int size=strlen(num2);
        
        num1=append_zeroes(num1,size);
        printf("%s",num1);
        
        bool carry=addNums(num1,num2,size);
        
        if(carry){
            char* ret_arr=(char*)malloc((size+2)*sizeof(char));
            memcpy(ret_arr+1,num1,size);
            *ret_arr='1'; *(ret_arr+size+1)='\0';
            return ret_arr;
        }
        char* ret_arr=(char*)malloc((size+1)*sizeof(char));
        memcpy(ret_arr,num1,size);
        *(ret_arr+size)='\0';
        return ret_arr;
    }
    else if(strlen(num1) > strlen(num2)){
            
        int size=strlen(num1);
        num2=append_zeroes(num2,size);
        
        bool carry=addNums(num1,num2,size);
        
        if(carry){
            char* ret_arr=(char*)malloc((size+2)*sizeof(char));
            memcpy(ret_arr+1,num1,size);
            *ret_arr='1'; *(ret_arr+size+1)='\0';
            return ret_arr;
        }
        char* ret_arr=(char*)malloc((size+1)*sizeof(char));
        memcpy(ret_arr,num1,size);
        *(ret_arr+size)='\0';
        return ret_arr;
    }
        int size=strlen(num1);
        bool carry=addNums(num1,num2,size);
        
        if(carry){
            char* ret_arr=(char*)malloc((size+2)*sizeof(char));
            memcpy(ret_arr+1,num1,size);
            *ret_arr='1'; *(ret_arr+size+1)='\0';
            printf("Here");
            return ret_arr;
        }
        char* ret_arr=(char*)malloc((size+1)*sizeof(char));
        memcpy(ret_arr,num1,size);
        *(ret_arr+size)='\0';
        return ret_arr;
}
