class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.size()!=t.size()) return false;
        unordered_map<char,int> smpp;
        unordered_map<char,int> tmpp;

        for(int i=0;i<s.size();i++)
        {
            char c1= s[i];
            char c2= t[i];

            if(smpp.count(c1) && smpp[c1]!=c2) return false;
            if(tmpp.count(c2) && tmpp[c2]!=c1) return false;

            smpp[c1]=c2;
            tmpp[c2]=c1;
        }
        return true;
    }
};