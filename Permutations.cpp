class Solution {
public:
    void func(int c, int n, vector<int>& nums, vector<vector<int>>& res, vector<int>& ans, unordered_map<int, bool>& visited) {
        if (c == n) {
            res.push_back(ans);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            visited[i] = true;
            ans.push_back(nums[i]);
            func(c + 1, n, nums, res, ans, visited);
            ans.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        unordered_map<int, bool> visited;
        for (int i = 0; i < nums.size(); i++) visited[i] = false;
        func(0, nums.size(), nums, res, ans, visited);
        return res;
    }
};

//N*N!
