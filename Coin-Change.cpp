class Solution {
public:
    int func(int idx, int amount, const vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 0;        // No coins needed
        if (amount < 0) return INT_MAX;   // Invalid path
        if (dp[idx][amount] != -1) return dp[idx][amount];

        int ans = INT_MAX;

        // Try all coins from current idx to 0 (reuse allowed)
        for (int i = idx; i >= 0; i--) {
            int res = func(i, amount - coins[i], coins, dp);
            if (res != INT_MAX)
                ans = min(ans, res + 1);  // +1 for the current coin used
        }

        return dp[idx][amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = func(n - 1, amount, coins, dp);
        return result == INT_MAX ? -1 : result;
    }
};