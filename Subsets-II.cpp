class Solution {
public:
    void func(int idx,int n,vector<int> nums,vector<vector<int>> &res,vector<int> ans)
    {
        if(idx==n)
        {
            return;
        }
        for(int i=idx;i<n;i++)
        {
            if(i>idx && nums[i]==nums[i-1]) continue;
            ans.push_back(nums[i]);
            res.push_back(ans);
            func(i+1,n,nums,res,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> ans;
        res.push_back(ans);
        sort(nums.begin(),nums.end());
        func(0,nums.size(),nums,res,ans);
        return res;
    }
};