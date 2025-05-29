class Solution {
public:
    void reverse(vector<int>&nums, int left,int right)
    {
        while(left<right)
        {
            swap(nums[left],nums[right]);
            left++;
            right--;
        }
    }
    void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        k=k%n;
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};