class Solution {
public:
    string triangleType(vector<int>& nums) 
    {
        string triangle[4]={"equilateral","isosceles","scalene","none"};
    
        if(nums[0]+ nums[1]>nums[2] && nums[1]+ nums[2]>nums[0] && nums[0]+ nums[2]>nums[1])
        {
            if(nums[0]==nums[1] && nums[1]==nums[2]) return triangle[0];
            else if(nums[0]==nums[1] || nums[1]==nums[2] || nums[2]==nums[0])
            {
            return triangle[1];
            }
            else return triangle[2];
        }
        else return triangle[3];
    }
};