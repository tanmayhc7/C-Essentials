/**************************************
605. Can Place Flowers
Suppose you have a long flowerbed in which some of the plots are planted and some are not. However, flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, where 0 means empty and 1 means not empty), and a number n, return if n new flowers can be planted in it without violating the no-adjacent-flowers rule.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: True
Example 2:
Input: flowerbed = [1,0,0,0,1], n = 2
Output: False
Note:
The input array won't violate no-adjacent-flowers rule.
The input array size is in the range of [1, 20000].
n is a non-negative integer which won't exceed the input array size.
**************************************/

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    //Corner Cases with bedSize<=2
    if(flowerbedSize==1 && !n) return 1;
    else if(flowerbedSize==1 && n>0) return !flowerbed[0];
    
    if(flowerbedSize==2){
        if(flowerbed[0]+flowerbed[1]) {
            if(n==0) return 1;
            else return 0;
        }
        else {
            if(n==1) return 1;
            else return 0;
        }
    }
    //Normal Case
    int potential_spots=0;
    for(int left=0,center=1,right=2;right<flowerbedSize;left++,center++,right++){
        if(left==0 && flowerbed[left]==0 && flowerbed[center]==0) {
            potential_spots++; flowerbed[left]=1;}
            if(flowerbed[left]+flowerbed[right]+flowerbed[center]==0) {
                potential_spots++; flowerbed[center]=1;
            }
        if(right==flowerbedSize-1 && flowerbed[right]==0 && flowerbed[center]==0) {
            potential_spots++; flowerbed[right]=1;}
        
    }
    return potential_spots>=n;
}
