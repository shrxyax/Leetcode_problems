class Solution {
public:
    void func(int idx,int n,vector<int> &ans,vector<vector<int>> &res,int target,vector<int> candidates)
    {
        if(idx==n)
        {
            if(target==0) res.push_back(ans);
            return;
        }
        if(candidates[idx]<=target)
        {
            ans.push_back(candidates[idx]);
            func(idx,n,ans,res,target-candidates[idx],candidates);
            ans.pop_back();
        }
        func(idx+1,n,ans,res,target,candidates);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> ans;
        vector<vector<int>> res;
        func(0,candidates.size(),ans,res,target,candidates);
        return res;
    }
};