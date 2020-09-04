/**********************************************
11. Container With Most Water

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, 
such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
**************************************************/
int getArea(int* h,int i,int j){
    return ((h[i]<h[j])?h[i]:h[j])*(j-i);
}
int maxArea(int* height, int hS){
    
    int left=0, right=hS-1;
    int area;
    int ret=INT_MIN;
    while(left<right){
        area=getArea(height,left,right);
        if(ret<area){
            ret=area;
        }
        if(height[left] <height[right]) left++;
        else if(height[left] >= height[right]) right--;
    }
    return ret;   
}
