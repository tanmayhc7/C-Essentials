/********************************************
	204. Count Primes
Count the number of prime numbers less than a non-negative number, n.

Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
********************************************/
//Implementation of the Sieve Eratosthenes' algorithm
int countPrimes(int n){
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    int count=0;
    for (int p=2; p<n; p++) 
    { 
        if (prime[p] == true) 
        { 
            count++;
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    return count;
}
