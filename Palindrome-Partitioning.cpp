class Solution {
public:
    bool palindrome(string s)
    {
        string rev=s;
        reverse(s.begin(),s.end());
        if(rev==s) return true;
        return false;
    }
    void palpar(int idx, string s, int n, vector<vector<string>> &res, vector<string> &ans)
    {
        if(idx==n)
        {
            res.push_back(ans);
            return;
        }

        for(int i=idx;i<n;i++)
        {
            if(palindrome(s.substr(idx,i-idx+1)))
            {
                ans.push_back(s.substr(idx,i-idx+1));
                palpar(i+1,s,n,res, ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        vector<string> ans;
        palpar(0,s,s.size(),res, ans);
        return res;
    }
};