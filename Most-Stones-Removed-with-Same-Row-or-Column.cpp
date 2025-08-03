class DisjointSet{
    public:
    vector<int> parent,rank;

    DisjointSet(int n)
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
        if(node==parent[node]) return node;
        return parent[node]=findPar(parent[node]);
    }
    void unionByRank(int u,int v)
    {
        int parent_u=findPar(u);
        int parent_v=findPar(v);
        if(parent_u==parent_v) return;
        if(rank[parent_u]<rank[parent_v]) parent[parent_u]=parent_v;
        else if(rank[parent_u]>rank[parent_v]) parent[parent_v]=parent_u;
        else
        {
            parent[parent_u]=parent_v;
            rank[parent_v]++;
        } 
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) 
    {
        int totstones=0;
        int max_a=0,max_b=0;
        for(int i=0;i<stones.size();i++)
        {
            totstones++;
            if(stones[i][0]>max_a) max_a=stones[i][0];
            if(stones[i][1]>max_b) max_b=stones[i][1];
        }
        DisjointSet ds(max_a+2+max_b);
        unordered_set<int> nodes;
        for(int i=0;i<stones.size();i++)
        {
            ds.unionByRank(stones[i][0],stones[i][1]+1+max_a);
            nodes.insert(stones[i][0]);
            nodes.insert(stones[i][1]+1+max_a);

        }
        int components=0;
        for(int n:nodes)
        {
            if(ds.findPar(n)==n) components++;
        }
        return totstones- components;

    }
};