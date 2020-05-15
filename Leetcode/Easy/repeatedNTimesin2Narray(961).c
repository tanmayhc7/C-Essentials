/*
 * In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

Return the element repeated N times.
 */
int repeatedNTimes(int* A, int Asize){
    int res=0;
    int count=Asize/2;
    int k=1;
    int cur=0;
    bool flag=0;

    for(int i=0;i<Asize;i++)
    {
        cur=A[i];
        for(int j=i+1;j<Asize;j++)
        {
            if(cur==A[j])
            {
                k++;
            }
            if(k==count)
            {
                res=cur;
                flag=1;
                break;
            }
        }
        if(flag) break;
    }
    return res;
}
