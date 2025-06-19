class Solution {
    int func(int i,int j, int m, int n,vector<vector<int>> &grid)
    {
        if(i==m-1 && j==n-1) return 1;
        if(i==m) return 0;
        if(j==n) return 0;

        if(grid[i][j]!=-1) return grid[i][j];
        int down= func(i+1,j,m,n,grid);
        int right=func(i,j+1,m,n,grid);
        return grid[i][j]=down +right;
    }
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> grid(m,vector<int>(n,-1));
        return func(0,0,m,n,grid);
    }
};