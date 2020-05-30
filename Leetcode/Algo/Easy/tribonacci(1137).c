/*
 * The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
 */
//Iterative
int tribonacci(int n){
    if (n < 2) return n;
        int a = 0, b = 1, c = 1, d = a + b + c;
        while (n-- > 2) {
            d = a + b + c, a = b, b = c, c = d;
        }
        return c;
}
//Recursive
int tribonacci(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    if (n==2) return 1;
    return tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
}
