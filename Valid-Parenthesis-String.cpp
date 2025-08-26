class Solution {
public:
    map<pair<int,int>,bool> dp;
    bool check(int i,int len,string &s,int c)
    {
        if(c<0) return false;
        if(len==i)
        {
            if(c==0) return true;
            return false;
        }
        pair<int,int> state={i,c};// auto state=make_pair{i,c};
        bool ans=false;
        if(dp.count(state)) return dp[state];
        if(s[i]=='(')
        {
            ans=check(i+1,len,s,c+1);
        } 
        else if(s[i]==')')
        {
            ans=check(i+1,len,s,c-1);
        } 
        else if(s[i]=='*')
        {
            ans=(  (check(i+1,len,s,c+1)) || check(i+1,len,s,c) || check(i+1,len,s,c-1) );
        }
        return dp[state]=ans;
    }
    bool checkValidString(string s) 
    {
        dp.clear();
        int c=0;
        return check(0,s.size(),s,c);
    }
};