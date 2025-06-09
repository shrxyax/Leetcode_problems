class Solution {
public:
    void func(int idx,string s,string digits,unordered_map<char,string> digToChar,vector<string> &ans,int n)
    {
        if(idx==n)
        {
            ans.push_back(s);
            return;
        }
        for(auto c:digToChar[digits[idx]])
        {
            func(idx+1,s+c,digits,digToChar,ans,n);
        }

    }
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        int n=digits.size();
        if(digits==\\) return ans;
        unordered_map<char,string> digToChar={{'2',\abc\},{'3',\def\},{'4',\ghi\},{'5',\jkl\},{'6',\mno\},{'7',\pqrs\},{'8',\tuv\},{'9',\wxyz\}};
        func(0,\\,digits,digToChar,ans,n);
        return ans;
    }
};