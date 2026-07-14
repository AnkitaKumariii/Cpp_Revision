class Solution {
public:
    int rows, cols;
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0 || visited[r][c]) {
            return 0;
        }
        visited[r][c] = 1;
        return 1 + dfs(r + 1, c, grid, visited) + dfs(r - 1, c, grid, visited) + dfs(r, c + 1, grid, visited) + dfs(r, c - 1, grid, visited);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows= grid.size();
        cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int area = 0;
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                area = max(area, dfs(r, c, grid, visited));
            }
        }
        return area;
    }
};
