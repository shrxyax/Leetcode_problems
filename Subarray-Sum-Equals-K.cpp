class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int n = nums.size();
        long long sum = 0;
        int c = 0;
        unordered_map<long long, int> m;
        m[sum] = 1;
        
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            int rem = sum-k;
            c += m[rem];
            m[sum]++;
        }
        return c;
    }
};

