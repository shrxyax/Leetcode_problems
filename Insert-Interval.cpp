class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int start=newInterval[0];
        int end=newInterval[1];

        vector<vector<int>> res;
        
        int i=0;
        int n=intervals.size();
        while(i<n && start>intervals[i][1])
        {
            res.push_back(intervals[i]);
            i++;
        }

        while(i<n && end>=intervals[i][0])
        {
            start=min(start,intervals[i][0]);
            end=max(end,intervals[i][1]);
            i++;
        }
        res.push_back({start,end});

        while(i<n)
        {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};