class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int start=0;
        int end=matrix.size()-1;
        int m=matrix[0].size();
        while(start<end)
        {
            int n=0;
            while(n<m)
            {
                swap(matrix[start][n],matrix[end][n]);
                n++;
            }
            start++;end--;
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i<j)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
    }
};