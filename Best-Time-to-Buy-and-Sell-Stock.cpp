class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit=0,mini=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            profit=max(prices[i]-mini,profit);
            mini=min(mini,prices[i]);
        }
        if(profit<=0) return 0;
        else return profit;
    }
};