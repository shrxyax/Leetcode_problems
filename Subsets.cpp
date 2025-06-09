class Solution {
public:
    void func(vector<int> &nums,vector<vector<int>> &result,int i,int n,vector<int> &ans)
    {
        if(i==n)
        {
            result.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        func(nums,result,i+1,n,ans);
        ans.pop_back();
        func(nums,result,i+1,n,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> result;
        vector<int>ans;
        int n=nums.size();
        func(nums,result,0,n,ans);
        return result;
    }
};

//power set;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> result;
        int size=1<<nums.size();
        for(int i=0;i<size;i++)
        {
            vector<int> subset;
            for(int j=0;j<nums.size();j++)
            {
                if((i&(1<<j))!=0) subset.push_back(nums[j]);
            }
            result.push_back(subset);

        }
        return result;
    }
};