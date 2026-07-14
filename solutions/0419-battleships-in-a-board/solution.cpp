class Solution {
public:
    int rows, cols;
    int dfs(int r, int c, vector<vector<char>>& board, vector<vector<bool>>& visited) {
        if(r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] == '.' || visited[r][c]) {
            return 0;
        }
        visited[r][c] = true;
        return 1 + dfs(r + 1, c, board, visited) + dfs(r - 1, c, board, visited) + dfs(r, c + 1, board, visited) + dfs(r, c - 1, board, visited);
    }
    int countBattleships(vector<vector<char>>& board) {
        rows= board.size();
        cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = 0;
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(board[r][c] == 'X' && !visited[r][c]) {
                    dfs(r, c, board, visited);
                    count++;
                }
            }
        }
        return count;
    }
};


