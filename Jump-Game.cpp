class Solution {
public:
    bool func(vector<int>& nums, int idx, int len, vector<int>& dp) {
        if (idx == len) return true;
        if (idx > len) return false;

        if (dp[idx] != -1) return dp[idx]; // already computed

        for (int jump = 1; jump <= nums[idx]; jump++) {
            if (func(nums, idx + jump, len, dp)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); // -1 = unvisited, 0 = false, 1 = true
        return func(nums, 0, n - 1, dp);
    }
};
