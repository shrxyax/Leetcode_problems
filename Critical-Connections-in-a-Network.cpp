class Solution {
public:
    int timer=0;
    void dfs(int node, int parent,vector<int> &tn, vector<int> &low, vector<int> &vis, vector<vector<int>> &adj, vector<vector<int>> &res )
    {
        vis[node]=1;
        tn[node]=low[node]=timer;
        timer++;

        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it,node,tn,low,vis,adj,res);
                low[node]=min(low[it],low[node]);
                if(tn[node]<low[it])
                {
                    res.push_back({node,it});
                }
            }
            else if(it!=parent)
            {
                low[node]=min(low[it],low[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>> adj(n);
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<int> tn(n);
        vector<int> low(n);
        vector<int> vis(n,0);

        vector<vector<int>> res;

        dfs(0,-1,tn,low,vis,adj,res);
        return res;
    }
};