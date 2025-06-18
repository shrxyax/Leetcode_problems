class Solution {
public:
    int func(int idx, vector<int> nums ,vector<int> &dp)
    {
        if(idx==nums.size()-1) return nums[idx];
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];

        int pick=nums[idx] + func(idx+2,nums,dp);
        int n_pick=0+ func(idx+1,nums,dp);

        return dp[idx]=max(pick,n_pick);
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> dp(n-1,-1);
        return func(0,nums,dp);
    }
};