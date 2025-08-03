class DisjointSet{
    public:
    vector<int> parent,size;

    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    int findPar(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=findPar(parent[node]);
    }
    void unionBySize(int u,int v)
    {
        int parent_u=findPar(u);
        int parent_v=findPar(v);
        if(parent_u==parent_v) return;
        if(size[parent_u]<size[parent_v])
        {
            parent[parent_u]=parent_v;
            size[parent_v]+=size[parent_u];
        }
        else
        {
            parent[parent_v]=parent_u;
            size[parent_u]+=size[parent_v];
        } 
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        DisjointSet ds(n*n);
        int c=0;
        vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 )
                {
                    c++;
                    for(int k=0;k<4;k++)
                    {
                        int a=i+dirs[k][0];
                        int b=j+dirs[k][1];
                        if(a>=0 && a<n && b>=0 && b<n && grid[a][b]==1)
                        {
                            int node=i*n+j;
                            int adjnode=a*n+b;
                            if(ds.findPar(node)!=ds.findPar(adjnode))
                            {
                                ds.unionBySize(node,adjnode);
                            }
                        }
                    }
                }
            }
        }
        if(c==n*n) return c;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    unordered_set<int> s;
                    for(int k=0;k<4;k++)
                    {
                        int a=i+dirs[k][0];
                        int b=j+dirs[k][1];
                        if(a>=0 && a<n && b>=0 && b<n && grid[a][b]==1)
                        {
                            int adjnode=a*n+b;
                            s.insert(ds.findPar(adjnode));
                        }
                    }
                    int sum=0;
                    for( int island:s)
                    {
                        sum+=ds.size[island];
                    }
                    maxi=max(maxi,sum+1);

                }
            }
        }

        return maxi;
    }
};