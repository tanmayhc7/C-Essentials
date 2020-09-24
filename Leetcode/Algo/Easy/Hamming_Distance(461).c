/*********************
461. Hamming Distance

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 = x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ?   ?

The above arrows point to positions where the corresponding bits are different.
***********************/
int hammingDistance(int x, int y){
    int res=0;
    int z=x^y; // z contains 1 for the bits that are opposite in x and y
    while(z){
        if(z&1) res++;
        z>>=1;
    }
    return res;
}
