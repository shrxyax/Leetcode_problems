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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        unordered_map<string,int> mpp;
        DisjointSet ds(accounts.size());
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mpp.find(accounts[i][j])==mpp.end())
                {
                    mpp[accounts[i][j]]=i;
                }
                else
                {
                    int u=mpp[accounts[i][j]];
                    ds.unionByRank(u,i); 
                }
            }
        }
        
        vector<vector<string>> merged(accounts.size());
        for(auto m:mpp)
        {
            string email=m.first;
            int idx=ds.findPar(m.second);
            merged[idx].push_back(email);
        }

        int n=accounts.size();
        vector<vector<string>> res;
        for(int i=0;i<n;i++)
        {
            if(merged[i].size()==0) continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto s:merged[i])
            {
                temp.push_back(s);
            }
            res.push_back(temp);
        }
        return res;
    }
};