/*****************************************************
202. Happy Number

Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*****************************************************/

/**
 ** If n is an unhappy num,the final loop would be
 ** 4 - 16 - 37 - 58 - 89 - 145 - 42 - 20 - 4
 ** So here we just need to verify whether these number 
 ** will appear in the calculate process 
 **/

bool isHappy(int n){
    if(ceil(log10(n)) == floor(log10(n))) return 1;
    
    if(n==4) return 0;
    
    int sum=0;
    while(n){
        sum+=(n%10)*(n%10);
        n/=10;
    }
    return isHappy(sum);     
} 

