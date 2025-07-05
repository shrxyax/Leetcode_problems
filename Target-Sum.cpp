class Solution {
public:
    int func(int idx, int target, vector<int>& nums, unordered_map<string, int>& memo) {
        if (idx < 0) {
            return (target == 0) ? 1 : 0;
        }

        // Create a unique key using idx and target
        string key = to_string(idx) + "|" + to_string(target);
        if (memo.count(key)) return memo[key];

        int plus = func(idx - 1, target - nums[idx], nums, memo);
        int minus = func(idx - 1, target + nums[idx], nums, memo);

        memo[key] = plus + minus;
        return memo[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return func(nums.size() - 1, target, nums, memo);
    }
};
