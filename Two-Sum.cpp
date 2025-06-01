class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> copy;
        copy.insert(copy.begin(),nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums.size()-1;
        vector<int> arr(2,-1);
        int left_ele=0,right_ele=0;
        while(left<right)
        {
            if(nums[left]+nums[right]<target)
            {
                left++;
                right=nums.size()-1;
            }
            else if(nums[left]+nums[right]>target)
            {
                right--;
            }
            else
            {
                left_ele=nums[left];
                right_ele=nums[right];
                break;
            }
        }
        for(int i=0;i<copy.size();i++)
        {
            if((copy[i]==left_ele) && (arr[0]==-1))
            {
                arr[0]=i;
            }
            else if(copy[i]==right_ele)
            {
                arr[1]=i;
            }
        }
        return arr;
    }
};