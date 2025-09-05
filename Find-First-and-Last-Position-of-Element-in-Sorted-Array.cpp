class Solution {
public:
    int findFirst(vector<int>& nums, int target)
    {
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target)
    {
        int low=0,high=nums.size()-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                low=mid+1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int first= findFirst(nums,target);
        int last=findLast(nums,target);
        return {first,last};
    }
};