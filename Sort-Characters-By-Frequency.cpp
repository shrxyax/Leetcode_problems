class Solution {
public:
    string frequencySort(string s) 
    {
        priority_queue< pair<int,char>, vector<pair<int,char>> >pq;
        unordered_map<char,int> mpp;
        for(char c:s)
        {
            mpp[c]++;
        }
        
        vector<string> buckets(s.size()+1);
        for(auto it:mpp)
        {
            buckets[it.second].append(it.second,it.first);
        }
        string st="";
        for(int i=buckets.size()-1;i>0;i--)
        {
            if(!buckets[i].empty())
            {
                st+=buckets[i];
            }
        }
        return st;
    }
};