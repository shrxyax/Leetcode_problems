class Solution {
public:
    bool isValid(string s) 
    {
        stack<int> st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                char m =st.top();
                if((m=='(' && s[i]==')') || (m=='{' && s[i]=='}') || (m=='[' && s[i]==']')) st.pop();
                else st.push(s[i]);
            }
        }
        return st.empty();
    }
};