class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int land = 0;

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    land++;
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                        q.push({i, j});
                        visited[i][j] = true;
                    }
                }
            }
        }

        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    grid[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }

        int borderLand = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (visited[i][j])
                    borderLand++;

        return land - borderLand;
    }
};
