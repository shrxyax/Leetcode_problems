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