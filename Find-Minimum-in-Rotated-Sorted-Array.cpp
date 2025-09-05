class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int low=0,high=nums.size()-1;
        int mini=INT_MAX;
        while(low<=high)
        {
            int mid=(high+low)/2;

            //sorted
            if(nums[low]<=nums[mid])
            {
                if(mini>nums[low]) mini=nums[low];
                low=mid+1;
            }

            else
            {
                if(mini>nums[mid]) mini=nums[mid];
                high=mid-1;
            }
        }
        return mini;
    }
};