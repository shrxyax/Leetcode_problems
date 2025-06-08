class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> ans(nums.size(),1);
        int curr=1;
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=ans[i]*curr;
            curr=curr*nums[i];
        }
        curr=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i]=ans[i]*curr;
            curr=curr*nums[i];
        }
        return ans;
    }
};