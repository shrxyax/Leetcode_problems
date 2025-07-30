class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) 
    {
        vector<vector<pair<int,int>>> adj(n);
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;            
        vector<int> count(n,0);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        for(int i=0;i<n;i++)
        {
            vector<int> count_node(n,0);
            vector<int> dist(n,INT_MAX);
            pq.push({0,i});
            dist[i]=0;
            while(!pq.empty())
            {
                auto ele= pq.top();pq.pop();
                int node=ele.second; int d=ele.first;
                for(auto it: adj[node])
                {
                    int node_it=it.first;int dist_it=it.second;
                    if(dist[node_it]>dist_it+d && dist_it+d<=k)
                    {
                        count_node[node_it]=1;
                        dist[node_it]=dist_it+d;
                        pq.push({dist_it+d,node_it});
                    }
                }
            }
            int c=0;
            for(auto it:count_node)
            {
                if(it==1) c++;
            }
            count[i]=c;
        }
        int mini=count[0];
        int idx=0;
        for(int i=1;i<n;i++)
        {
            if(mini>=count[i])
            {
                mini=count[i];
                idx=i;
            }
        }
        return idx;
    }
};