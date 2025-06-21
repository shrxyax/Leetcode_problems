class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();

        for (int i = 1; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    // Only one way to come to first element of row
                    triangle[i][j] += triangle[i - 1][j];
                }
                else if (j == i) {
                    // Only one way to come to last element of row
                    triangle[i][j] += triangle[i - 1][j - 1];
                }
                else {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }

        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, triangle[m - 1][j]);
        }

        return mini;
    }
};
