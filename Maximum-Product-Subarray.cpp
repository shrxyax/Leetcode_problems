class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int prod=1,max_prod=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(prod==0) prod=1;
            prod=prod*nums[i];
            max_prod=max(max_prod,prod);
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(prod==0) prod=1;
            prod=prod*nums[i];
            max_prod=max(max_prod,prod);
        }
        return max_prod;
    }

};