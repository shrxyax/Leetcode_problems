class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) 
    {
        unordered_set<int> s;
        unordered_set<int> curr;
        for(int i:arr)
        {
            unordered_set<int> next;
            next.insert(i);
            for(int j:curr)
            {
                next.insert(j|i);
            }
            curr=next;
            s.insert(curr.begin(),curr.end());
        }
        return s.size();
    }
};