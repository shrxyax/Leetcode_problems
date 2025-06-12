class Solution {
public:
    string permute(int &count, int idx, int n, int k, string s) {
        if (idx == n) {
            count++;
            if (count == k) return s;
            return \\;
        }

        // Sort the string starting from current index to maintain lex order
        sort(s.begin() + idx, s.end());

        for (int i = idx; i < n; i++) {
            
            swap(s[i], s[idx]);

            string result = permute(count, idx + 1, n, k, s);
            if (!result.empty()) return result;

            swap(s[i], s[idx]); // Backtrack
        }

        return \\;
    }

    string getPermutation(int n, int k) {
        int count = 0;
        string s = \\;
        for (int i = 1; i <= n; i++) s += (i + '0');
        return permute(count, 0, n, k, s);
    }
};
