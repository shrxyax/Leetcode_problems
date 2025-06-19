class Solution {
    int func(int i,int j, int m, int n,vector<vector<int>> &grid)
    {
        if(i==m-1 && j==n-1) return 1;

        if(i==m || j==n || grid[i][j]==-2) return 0;

        if(grid[i][j]!=-1 ) return grid[i][j];
        int down= func(i+1,j,m,n,grid);
        int right=func(i,j+1,m,n,grid);
        return grid[i][j]=down +right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& oG) 
    {
        int m=oG.size();
        int n=oG[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(oG[i][j]==1) oG[i][j]=-2;
                else oG[i][j]=-1;
            }
        }
        if(oG[0][0]==-2 || oG[m-1][n-1]==-2) return 0;
        return func(0,0,m,n,oG);
    }
};

