class Solution {
public:
    double minimumAverage(vector<int>& nums) 
    {
        int m=nums.size()/2;
        int n=nums.size()-1;
        sort(nums.begin(),nums.end());
        int i=0;
        double min_avg=DBL_MAX;
        while(m>0)
        {
            double avg=(nums[i]+nums[n-i])/2.0;
            min_avg=min(min_avg,avg);
            i++;
            m--;
        }
        return min_avg;
    }
};