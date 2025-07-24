class Solution {
public:
    void dfs(int node, vector<vector<int>> adjls, vector<int> &vis)
    {
        vis[node]=1;
        for(auto it: adjls[node])
        {
            if(!vis[it])
            {
                dfs(it,adjls,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int provinces=0;
        int cities=isConnected.size();
        vector<int> vis(cities,0);
        vector<vector<int>> adjls(cities);

        //changing adjacency matrix to list
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected.size();j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        for(int i=0;i<adjls.size();i++)
        {
            if(!vis[i])
            {
                dfs(i,adjls,vis);
                provinces++;
            }
        }
        return provinces;
    }
};