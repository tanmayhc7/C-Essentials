/*********************************
	409. Longest Palindrome
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*********************************/
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

int longestPalindrome(char * s){
    int arr[52]={0};//lower half ->lowercase
    
    for(int i=0;i<strlen(s);i++){
        if(s[i]>=97 && s[i]<=122){
            arr[s[i]-'a']++;
        }
        else{
            arr[s[i]-'A'+26]++;
        }
    }
    quickSort(arr,0,51);    
    
    int count=0;
    int i=51;
    int odd=0;
    //Allow only 1 odd occurrence
    //For other odd occurrences subtract 1
    for(;arr[i]>1 && i>=0;i--){
        
        if(arr[i]%2==1){
            if(odd>=1){
                count+=arr[i]-1; odd++;
            } else{
            count+=arr[i]; odd++;    
            }
        } else{
            count+=arr[i];
        }
        
    }
    //if all occurrences >1 have been even
    if(i>=0 && arr[i]==1 && !odd) count++;
    
    return count;
    
}
