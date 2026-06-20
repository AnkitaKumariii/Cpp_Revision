class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m, string(n, '#'));
        for(int i = 0; i<n; i++) {
            ans[0][i] = '.';
        }
        for(int j = 0; j<m; j++) {
            ans[j][n-1] = '.';
        }
        return ans;
    }
};
