class Solution {
public:
    bool check(int row,int col,int n,vector<string> ans)
    {
        int duprow=row,dupcol=col;
        int dr=row;
        while(row>=0 && col<n)
        {
            if(ans[row--][col++]=='Q') return false;
        }
        while(duprow>=0)
        {
            if(ans[duprow--][dupcol]=='Q') return false;
        }
        while(dr>=0 && dupcol>=0)
        {
            if(ans[dr--][dupcol--]=='Q') return false;
        }
        return true;
    }
    void nQueen(int row,int n,vector<string> &ans,vector<vector<string>> &res)
    {
        if(row==n)
        {
            res.push_back(ans);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(check(row,i,n,ans))
            {
                ans[row][i]='Q';
                nQueen(row+1,n,ans,res);
                ans[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> ans(n);
        vector<vector<string>> res;
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            ans[i]=s;
        }
       nQueen(0,n,ans,res);
       return res;
    }
};