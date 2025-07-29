class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> mini(n+1,INT_MAX);
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,k});
        mini[k]=0;
        //    time node
        while(!pq.empty())
        {
            auto ele= pq.top();
            pq.pop();
            int time= ele.first;
            int curr= ele.second;
            for(auto it: adj[curr])
            {
                int next= it.first;
                int it_time= it.second;
                if(mini[next]>time+it_time)
                {
                    mini[next]= time+it_time;
                    pq.push({time+it_time,next});
                }
            }
        }
        int time=INT_MIN;
        for(int i=1;i<mini.size();i++)
        {
            if(mini[i]==INT_MAX) return -1;
            time=max(time,mini[i]);
        }
        return time;
    }
};