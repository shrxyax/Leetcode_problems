class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int el=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0) el=nums[i];
            if(nums[i]==el) count++;
            else count--;
        }
        return el;

        //do this only if it says that there might not be a majority element

        /*int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==el) c++;
        }
        if(c>=(nums.size()/2)) return el;
        return -1;
        */
    }
};