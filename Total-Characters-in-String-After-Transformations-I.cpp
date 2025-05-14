3335. Total Characters in String After Transformations I

class Solution {
public:
    int lengthAfterTransformations(string s, int t) 
    {
        int MOD= 1e9 + 7;
        vector<int>freq(26,0);
        for(int c:s)
        {
            freq[(int)c-97]++;
        }
        while(t--)
        {
            vector<int>nextFreq(26,0);
            for(int i=0;i<25;i++)
            {
                nextFreq[i+1]=(nextFreq[i+1]+freq[i])%MOD;
            }
            nextFreq[0]=(nextFreq[0]+freq[25])%MOD;
            nextFreq[1]=(nextFreq[1]+freq[25])%MOD;
            freq=nextFreq;
        }
        int length=0;
        for(int i=0;i<26;i++)
        {
            length=(length+freq[i])%MOD;
        }
        return length;
    }

};
