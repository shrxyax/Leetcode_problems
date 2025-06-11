class Solution {
public:
    void func(int idx, int n, vector<int>& nums, vector<vector<int>>& res) {
        if(idx==n)
        {
            res.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            swap(nums[idx],nums[i]);
            func(idx+1,n, nums, res);
            swap(nums[i],nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;

        func(0,nums.size(), nums, res);
        return res;
    }
};

//another method is hashing and storing true false

//N*N!
