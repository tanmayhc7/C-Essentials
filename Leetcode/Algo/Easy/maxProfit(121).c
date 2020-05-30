/*
 * Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.
 */
int maxProfit(int* prices, int pricesSize){

    int result=0;

    for(int i=0;i<pricesSize;i++)
    {
        for(int j=i+1;j<pricesSize;j++)
        {
            if((prices[i]<prices[j]) && (result<prices[j]-prices[i]))
            {
                result=prices[j]-prices[i];
            }
        }
    }
    return result;
}

