class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int first=nums[0];
        int c=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-first>k)
            {
                c++;
                first=nums[i];
            }
        }
        return c ;
    }
};