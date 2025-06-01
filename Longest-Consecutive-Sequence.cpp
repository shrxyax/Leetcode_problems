class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size()==0) return 0;
        int max_c=0;
        sort(nums.begin(),nums.end());
        int c=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if((nums[i]+1)==nums[i+1]) c++;
            else
            {
                max_c=max(c,max_c);
                if(nums[i]!=nums[i+1]) c=0;
            }
        }
        max_c=max(c,max_c);
        return max_c+1;
    }
};