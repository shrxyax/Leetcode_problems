class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        int MOD= 1e9 + 7;
       priority_queue< pair<long long,long long> , vector<pair<long long,long long>> , greater<pair<long long,long long>> > pq;

       vector<long long> dist(n,LLONG_MAX);
       vector<long long> ways(n,0);
       vector<vector<pair<int,int>>> adj(n);

       for(int i=0;i<roads.size();i++)
       {
        adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
       }
       pq.push({0,0});
       dist[0]=0;
       ways[0]=1;
       while(!pq.empty())
       {
        auto ele= pq.top();pq.pop();
        long long time= ele.first;
        long long node= ele.second;
        for(auto it: adj[node])
        {
            long long newtime= time+it.second;
            if(dist[it.first]>newtime)
            {
                pq.push({newtime,it.first});
                dist[it.first]=newtime;
                ways[it.first]=ways[node];
            }
            else if(dist[it.first]==newtime)
            {
                ways[it.first]=(ways[it.first]+ways[node])%MOD;
            }
        }
       } 
       return ways[n-1];
    }
};