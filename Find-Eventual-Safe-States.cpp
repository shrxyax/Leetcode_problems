class Solution {
public:
    bool dfs(vector<int> &vis,vector<int> &pathvis,vector<int> &safe, int node,vector<vector<int>>& graph)
    {
        vis[node]=1;
        pathvis[node]=1;
        for(auto it: graph[node])
        {
            if(!vis[it])
            {
                if(dfs(vis,pathvis,safe,it,graph)) return true;
            }
            else if(pathvis[it]) return true;

        }
        pathvis[node]=0;
        safe[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int V=graph.size();
       vector<int> vis(V,0);
       vector<int> pathvis(V,0);
       vector<int> safe(V,0);
       vector<int> vec;
       for(int i=0;i<V;i++)
       {
        if(!vis[i])
        {
            dfs(vis,pathvis,safe,i,graph);
        }
       }
       for(int i=0;i<V;i++)
       {
        if(safe[i]) vec.push_back(i);
       }
       return vec;
    }
};