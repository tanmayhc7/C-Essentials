/*************************************************************************
896. Monotonic Array
An array is monotonic if it is either monotone increasing or monotone decreasing.
An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
Return true if and only if the given array A is monotonic.

Example 1:

Input: [1,2,2,3]
Output: true
Example 2:

Input: [6,5,4,4]
Output: true
Example 3:

Input: [1,3,2]
Output: false
Example 4:

Input: [1,2,4,5]
Output: true
Example 5:

Input: [1,1,1]
Output: true
 

Note:

1 <= A.length <= 50000
-100000 <= A[i] <= 100000
****************************************************************************/

//Brute Force Time: O(n) Space:O(1)
bool isMonotonic(int* A, int s){
    if(s<=2) return 1;
    
    bool flag=1;
    
    int status=A[1]-A[0]; 
    if(status>0)
    {
        for(int i=1;i<s-1;i++)
        {
            if((A[i+1]-A[i]) >= 0)
            {
                continue;
            }
            else{
                return 0;
            }
        }    
    }
    else if(status<0)
    {
        for(int i=1;i<s-1;i++)
        {
            if((A[i+1]-A[i]) <= 0)
            {
                continue;
            }
            else{
                return 0;
            }
        }
    }
    else{
        char prev='c';
        char cur='c';
        for(int i=1;i<s-1;i++){
            if(!(A[i+1]-A[i])) 
            {
                continue;
            }
            else{
                if((A[i+1]-A[i]) > 0)
                {
                    cur='i';
                }
                if((A[i+1]-A[i]) < 0)
                {
                    cur='d';
                }
            }
            if((prev=='d' && cur=='i') || (prev=='i' && cur=='d')) return 0;
            prev=cur;
        }
    }
    return 1;
}

// Method 2: T:O(n) S:O(1)
bool isMonotonic(int* A, int s){
    int i,j;
    if(s<=2) return true;
    for(i=1;i<s && A[i-1]<=A[i];i++);
    for(j=1;j<s && A[j-1]>=A[j];j++);
    return i==s|j==s;
}
