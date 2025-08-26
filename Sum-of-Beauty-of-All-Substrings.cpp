class Solution {
public:
    int beautySum(string s) 
    {
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
            vector<int> freq(26,0);
            for(int j=i;j<s.size();j++)
            {
                freq[s[j]-'a']++;
                int h=0,l=INT_MAX;
                for(int f:freq)
                {
                    if(f>0)
                    {
                        h=max(f,h);
                        l=min(f,l);
                    }
                }
                sum+=(h-l);
            }
        }
        return sum;
    }
};