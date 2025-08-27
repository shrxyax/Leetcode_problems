class Solution {
public:
    int func1(vector<int>& nums, int idx, int len, vector<int>& dp) {
        if(idx >= len) return 0;       // reached last index
      // invalid index

        if(dp[idx] != -1) return dp[idx];

        int ans = 1e9;
        for(int jump = 1; jump <= nums[idx]; jump++) {
            int res = func1(nums, idx + jump, len, dp) + 1;
            ans = min(ans, res);
        }
        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) 
    {
        //vector<int> dp(nums.size(), -1);
        //return func1(nums, 0, nums.size() - 1, dp);

        int jumps=0;
        int l=0,r=0;
        int n=nums.size();
        while(r<n-1)
        {
            int farthest=0;
            for(int i=l;i<=r;i++)
            {
                farthest=max(farthest,nums[i]+i);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};
