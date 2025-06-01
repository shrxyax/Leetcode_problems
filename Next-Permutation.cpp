class Solution {
public:
    void nextPermutation(vector<int>& a) 
    {
        int c = 0;
        int p = 0;
        for (int i = a.size() - 2; i >= 0; i--) 
        {
            if (a[i] < a[i + 1]) 
            {
                c++;
                int x = INT_MAX;
                for (int j = i + 1; j < a.size(); j++) 
                {
                    if (a[j] > a[i] && a[j] <= x) 
                    {
                        x = a[j];
                        p = j;
                    }
                }
                swap(a[i], a[p]);
                reverse(a.begin() + i + 1, a.end());
                break;
            }
        }
        if (c == 0) 
        {
            sort(a.begin(), a.end());
        }
    }
};
