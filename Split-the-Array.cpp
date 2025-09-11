class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) 
    {
        int n=nums.size()/2;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
            if(mpp[nums[i]]>2) return false;
        }
        return true;
    }
};