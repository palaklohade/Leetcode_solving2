class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        visited[row][col] = true;

        for (int dir = 0; dir < 4; dir++) {
            int nx = row + dx[dir];
            int ny = col + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] &&
                grid[nx][ny] == '1') {
                dfs(nx, ny, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, visited);
                    count++;
                }
            }
        }
        return count;
    }
};