class Disjoint{
    public:
    vector<int> parent,rank;
    Disjoint(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    int findPar(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findPar(parent[node]);
    }

    void unionByRank(int u,int v)
    {
        int parent_u= findPar(u);
        int parent_v= findPar(v);
        if(parent_u== parent_v) return;
        int rank_u=rank[parent_u];
        int rank_v=rank[parent_v];
        
        if(rank_u>rank_v)
        {
            parent[parent_v]=parent_u;
        }
        else if(rank_u<rank_v)
        {
            parent[parent_u]=parent_v;
        }
        else 
        {
            parent[parent_u]=parent_v;
            rank[parent_v]++;
        }
    }

};

class Solution {
public:

    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int edges= connections.size();
        if(edges<n-1) return -1;

        int extras=0;
        Disjoint ds(n);
        for(int i=0;i<connections.size();i++)
        {
            if(ds.findPar(connections[i][0])==ds.findPar(connections[i][1])) extras++;
            else ds.unionByRank(connections[i][0],connections[i][1]);
        }
        int components=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i) components++;
        }
        if(extras<components-1) return-1;
        return components-1;
        
    }
};