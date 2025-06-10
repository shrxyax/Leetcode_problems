class Solution {
public:
    void func(int idx,int target,int n,vector<int> candidates,vector<int> &ans, vector<vector<int>> &res)
    {
        if(target==0)
        {
            res.push_back(ans);
            return;
        }

        for(int i=idx;i<n;i++)
        {
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ans.push_back(candidates[i]);
            func(i+1,target-candidates[i],n,candidates,ans,res);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        vector<int> ans;
        sort(candidates.begin(),candidates.end());
        func(0,target,candidates.size(),candidates,ans,res);
        return res;
    }
};