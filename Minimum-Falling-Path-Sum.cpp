class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        vector<int> sum(n);
        for(int j=0;j<n;j++)
        {
            sum[j]=matrix[0][j];
        }

        for(int i=1;i<n;i++)
        {
            vector<int> curr(n);
            for(int j=0;j<n;j++)
            {
                if(j==0)
                {
                    curr[j]=matrix[i][j]+ min(sum[j],sum[j+1]);
                }
                else if(j==n-1)
                {
                    curr[j]=matrix[i][j]+ min(sum[j],sum[j-1]);
                }
                else
                {
                    curr[j]=matrix[i][j]+ min(sum[j],min(sum[j+1],sum[j-1]));
                }
            }
            sum=curr;
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++)
        {
            mini=min(mini,sum[j]);
        }
        return mini;
    }
};