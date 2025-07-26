class Solution {
public:
    
    void solve(vector<vector<char>>& board)
    {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        queue<pair<int, int>> q;
        set<pair<int, int>> s;
        for (int i = 0; i < m ; ++i)
        {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && (i==0 || i==m-1 || j==0 || j==n-1)) {
                    q.push({i,j});
                    s.insert({i,j});// all the border O
                }
            }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (auto& [dx, dy] : dirs) 
            {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (board[nx][ny] == 'O' && s.find({nx, ny}) == s.end()) {
                        q.push({nx, ny});
                        s.insert({nx, ny});
                    }
                } 
            }
        }
        for (int i = 0; i < m ; ++i) 
        {
            for (int j = 0; j < n; ++j) {
                if (s.find({i,j})==s.end() && board[i][j]=='O') {
                    board[i][j]='X';
                }
            }
        }


    }
};
