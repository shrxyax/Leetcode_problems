class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int count1=0,count2=0,el1=0,el2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count1==0 && el2!=nums[i])
            {
                el1=nums[i];
                count1++;
            }
            else if(count2==0 && el1!=nums[i])
            {
                el2=nums[i];
                count2++;
            }
            else if(el1==nums[i]) count1++;
            else if(el2==nums[i]) count2++;
            else
            {
                count1--;
                count2--;
            }
        }
        int c1=0,c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==el1) c1++;
            else if(nums[i]==el2) c2++;
        }
        vector<int> ans;
        if(c1>(nums.size()/3)) ans.push_back(el1);
        if(c2>(nums.size()/3)) ans.push_back(el2);
        return ans;
    }
};