class Solution {
public:
    void func(int c, int n, vector<int>& nums, vector<vector<int>>& res,int a,int b) {
        if (c == n) {
            return;
        }
        while(b>=0)
        {
            swap(nums[a],nums[b]);
            res.push_back(nums);
            c++;
            if(c==n) return;
            b--;a--;
        }
        func(c,n,nums,res,nums.size()-1,nums.size()-2);
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(nums);
        if(nums.size()==1) return res;
        vector<int> ans;
        int n=1;
        for(int i=2;i<=nums.size();i++)
        {
            n=n*i;
        }
        func(1,n, nums, res, nums.size()-1,nums.size()-2);
        return res;
    }
};

//N*N!
