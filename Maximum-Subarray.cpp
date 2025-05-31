class Solution {
public:
    int maxSubArray(vector<int>& nums) 
{
        int n=nums.size();
        int res=nums[0];       //result should be initialized with first element
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum<0) sum=0;    //first we check if statement
            sum=sum+nums[i];    //and then do sum
            res=max(res,sum);   //otherwise there will error when entire array
                                //is of negative numbers
        }  
        return res;     
    }
};
