class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        // Build adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f: flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> mini(n,INT_MAX);
        queue<vector<int>> q;
        q.push({0,src,0});
        // stops node cost;
        mini[src]=0;
        while(!q.empty())
        {
            auto ele=q.front();
            q.pop();
            int stop=ele[0];
            int node=ele[1];
            int cost=ele[2];

            for(auto it: adj[node])
            {
                int next=it.first;
                int cost_it=it.second;
                if(mini[next]>cost+cost_it && stop<k+1)
                {
                    mini[next]=cost+cost_it;
                    q.push({stop+1,next,cost+cost_it});
                }
            }
        }
        return (mini[dst]==INT_MAX)?-1:mini[dst];
    }
};

