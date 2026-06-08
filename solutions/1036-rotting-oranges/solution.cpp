class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>, int>> q;  //{{row, col}, time}
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int countFresh = 0;
        for(int row = 0; row<n; row++) {
            for(int col = 0; col<m; col++) {
                if(grid[row][col] == 2) {
                    q.push({{row, col}, 0});
                    vis[row][col] = 2;  // apna rotten orange
                }
                else {
                    vis[row][col] = 0;
                }
                if(grid[row][col] == 1) countFresh++;  //agar fresh mila, mark kar do
            }
        }
        int time = 0;
        int count = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for(int i = 0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int row = 0; row<n; row++) {
            for(int col = 0; col<m; col++) {
                if(vis[row][col] != 2 && grid[row][col] == 1) {
                    return -1;
                }
            }
        }
        return time;
    }
};



