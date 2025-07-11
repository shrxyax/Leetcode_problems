class Solution {
public:
    int func(vector<int>& coins,int amount,int idx,vector<vector<int>> &dp)
    {
        if(idx==0)
        {
            if(amount==0) return 1;
            if(amount%coins[0]==0) return 1;
            return 0;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int ntake= func(coins,amount,idx-1,dp);
        int take=0;
        if(coins[idx]<=amount) take= func(coins,amount-coins[idx],idx,dp);
        return dp[idx][amount]=take+ntake;
    }
    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return func(coins,amount,n-1,dp);
    }
};