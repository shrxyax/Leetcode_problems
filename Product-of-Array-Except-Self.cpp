class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> ans(nums.size(),1);
        int curr=1;
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=ans[i]*curr;
            curr=curr*nums[i];
        }
        curr=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            ans[i]=ans[i]*curr;
            curr=curr*nums[i];
        }
        return ans;
    }
};

//less optimized approach
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int pre[] = new int[n];
        int suff[] = new int[n];
        pre[0] = 1;
        suff[n - 1] = 1;
        
        for(int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] * nums[i + 1];
        }
        
        int ans[] = new int[n];
        for(int i = 0; i < n; i++) {
            ans[i] = pre[i] * suff[i];
        }
        return ans;
    }
}
