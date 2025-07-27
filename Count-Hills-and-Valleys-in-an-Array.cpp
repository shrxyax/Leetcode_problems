class Solution {
public:
    int countHillValley(vector<int>& nums) 
    {
        int hill=0,valley=0;
        vector<int> arr;

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1]) arr.push_back(nums[i-1]);
        }
        arr.push_back(nums[nums.size()-1]);

        for(int i=1;i<arr.size()-1;i++)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) hill++;
            else if(arr[i]<arr[i-1] && arr[i]<arr[i+1]) valley++;

        }
        return hill+ valley;

    }
};