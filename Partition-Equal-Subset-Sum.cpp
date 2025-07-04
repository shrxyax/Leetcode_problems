class Solution {
public:
    int func(int idx, int sum, int tot, vector<int>& nums, vector<vector<int>>& dp) {
        if (sum == (tot - sum)) return 1;
        if (idx == 0) return (sum == (tot - sum)) ? 1 : 0;
        
        if (dp[idx][sum] != -1) return dp[idx][sum];
        
        int take = func(idx - 1, sum + nums[idx], tot, nums, dp);
        int notTake = func(idx - 1, sum, tot, nums, dp);
        
        return dp[idx][sum] = take | notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size(), tot = 0;
        for (int i = 0; i < n; i++) {
            tot += nums[i];
        }

        // Optimization: If total sum is odd, it's impossible to split equally
        if (tot % 2 != 0) return false;

        vector<vector<int>> dp(n, vector<int>(tot + 1, -1));
        return func(n - 1, 0, tot, nums, dp);
    }
};
