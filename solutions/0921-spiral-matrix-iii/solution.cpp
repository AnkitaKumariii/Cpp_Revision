class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int delrow[] = {0, 1, 0, -1};
        int delcol[] = {1, 0, -1, 0};
        vector<vector<int>>ans;
        int r = rStart, c = cStart;
        int steps = 1;
        int i = 0; 
        while(ans.size() < rows * cols) {
            for(int j = 0; j<2; ++j) {
                for(int k = 0; k<steps; k++) {
                    if(r >= 0 && r < rows && c >= 0 && c < cols) {
                        ans.push_back({r, c});
                    }
                    r += delrow[i];
                    c += delcol[i];
                }
                i = (i+1) % 4;
            }
            steps++;
        }
        return ans;
    }
};
