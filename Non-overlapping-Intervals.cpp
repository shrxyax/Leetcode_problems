class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        int check=intervals[0][1];
        int c=0;
        for(int i=1;i<intervals.size();i++)
        {
            if(check>intervals[i][0])
            {
                c++;
                check=min(check,intervals[i][1]);
            }
            else
            {
                check=intervals[i][1];
            }
        }
        return c;
    }
};