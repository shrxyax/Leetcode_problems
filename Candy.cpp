class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> count(n, 1); // each child gets at least one candy

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                count[i] = count[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && count[i] <= count[i + 1]) {
                count[i] = count[i + 1] + 1;
            }
        }
        int total = 0;
        for (int candies : count) total += candies;
        return total;
    }
};
