class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
       int count0=0,count1=0,count2=0;
       for(int i=0;i<nums.size();i++)
       {
        if(nums[i]==0) count0++;
        else if(nums[i]==1) count1++;
        else count2++;
       }
       int i=0;
       while(count0>0)
       {
        nums[i]=0;
        i++;count0--;
       }
       while(count1>0)
       {
        nums[i]=1;
        i++;count1--;
       }
       while(count2>0)
       {
        nums[i]=2;
        i++;count2--;
       }
    }
};


class Solution {
public:

    void sortColors(vector<int>& nums) 
    {
       int low=0;
       int mid=0;
       int high=nums.size()-1;
       while(mid<=high)
       {
        if(nums[mid]==0) swap(nums[mid++],nums[low++]);
        else if(nums[mid]==1) mid++;
        else swap(nums[mid],nums[high--]);
       } 
    }
};
