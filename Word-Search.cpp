class Solution {
public:
    bool check(int row, int col, int idx, vector<vector<char>>& board, string& word,
               int row_len, int col_len, vector<vector<bool>>& visited) {

        if (idx == word.size()) return true;

        if (row < 0 || col < 0 || row >= row_len || col >= col_len || visited[row][col] || board[row][col] != word[idx])
            return false;

        visited[row][col] = true;

        bool found = check(row - 1, col, idx + 1, board, word, row_len, col_len, visited) ||
                     check(row + 1, col, idx + 1, board, word, row_len, col_len, visited) ||
                     check(row, col - 1, idx + 1, board, word, row_len, col_len, visited) ||
                     check(row, col + 1, idx + 1, board, word, row_len, col_len, visited);

        visited[row][col] = false; // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row_len = board.size();
        int col_len = board[0].size();

        vector<vector<bool>> visited(row_len, vector<bool>(col_len, false));

        for (int i = 0; i < row_len; i++) {
            for (int j = 0; j < col_len; j++) {
                if (check(i, j, 0, board, word, row_len, col_len, visited))
                    return true;
            }
        }

        return false;
    }
};
