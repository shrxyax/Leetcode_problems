class Solution {
public:
    bool word(int idx, string &s, vector<string> &wordDict, int n, int m, vector<int> &dp)
    {
        if (idx == m) return true;
        if (dp[idx] != -1) return dp[idx]; // memoized result

        for (int i = 0; i < n; i++)
        {
            int len = wordDict[i].size();
            if (idx + len <= m && s.substr(idx, len) == wordDict[i])
            {
                if (word(idx + len, s, wordDict, n, m, dp)) 
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        int m = s.size(), n = wordDict.size();
        vector<int> dp(m, -1); // -1: unvisited, 0: false, 1: true
        return word(0, s, wordDict, n, m, dp);
    }
};
