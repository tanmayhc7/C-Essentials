/****************************************************8
169. Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
******************************************************/

//Method 1: Sorting & then traverse every element

//Method 2: Since the majority element occurs more than (n/2) times, there will be a sequence of that number occuring in the array.
//So harness that property to increase & decrease the counter and when it hits zero, init the result to the arr[i]
int majorityElement(int* num, int n){
    int cnt = 0, res;
    for (int i = 0; i < n; ++i) {
        if (cnt == 0) res = num[i];
        if (res == num[i]) ++cnt;
        else --cnt;
    }
    return res;
}
