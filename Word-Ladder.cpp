class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> s;
        queue<pair<string,int>> q;
        int c=0;
        for(auto si:wordList)
        {
            s.insert(si);
            if(si==endWord) c++;
        }
        if(c==0) return 0;
        int len= beginWord.size();

        q.push({beginWord,1});
        while(!q.empty())
        {
            string word= q.front().first;
            int t=q.front().second;
            q.pop();
            for(int i=0;i<len;i++)
            {
                string temp=word;
                for(char c='a';c<='z';c++)
                {
                    temp[i]=c;
                    if(temp==endWord) return t+1;
                    if(s.count(temp))
                    {
                        s.erase(temp);
                        q.push({temp,t+1});
                    }
                }
            }
        }
        return 0;
    }
};