class Solution {


public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();


        vector<int> sum(n);
        sum[0]=grid[0][0];
        for(int j=1;j<n;j++)
        {
            sum[j]=sum[j-1]+grid[0][j];
        }
        for(int i=1;i<m;i++)
        {
            vector<int> curr(n);
            for(int j=0;j<n;j++)
            {
                if(j==0) curr[j]=sum[j]+grid[i][j];
                else
                {
                    curr[j]=grid[i][j] + min(sum[j],curr[j-1]);
                }
            }
            sum=curr;
        }
        return sum[n-1];
    }
};
