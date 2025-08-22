class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;

        queue<tuple<int,int,int>> q; 

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j, 0});
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;
        int dRow[4] = {-1, 0, 1, 0};
        int dCol[4] = {0, -1, 0, 1};

        while(!q.empty()) {
            auto [r, c, t] = q.front();
            q.pop();
            time = max(time, t);

            for(int k = 0; k < 4; k++) {
                int nr = r + dRow[k];
                int nc = c + dCol[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;   
                    fresh--;
                    q.push({nr, nc, t + 1});
                }
            }
        }

        return (fresh == 0) ? time : -1;
    }
};