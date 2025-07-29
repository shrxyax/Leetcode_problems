class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> mini(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        mini[0][0]=0;
        vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        while(!pq.empty())
        {
            auto ele= pq.top();
            pq.pop();
            int dist=ele.first;
            int x=ele.second.first;
            int y=ele.second.second;

            if(x==n-1 && y==m-1) return dist;
            for(int i=0;i<4;i++)
            {
                int nx= dirs[i][0]+x;
                int ny= dirs[i][1]+y;
                if(nx>=0 && nx<n && ny>=0 && ny<m )
                {
                    int newdist= max(dist,abs(heights[nx][ny]-heights[x][y]));
                    if(mini[nx][ny]>newdist)
                    {
                        pq.push({newdist,{nx,ny}});
                        mini[nx][ny]=newdist;
                    }
                }
            }
        }
        return mini[n-1][m-1];
    }
};