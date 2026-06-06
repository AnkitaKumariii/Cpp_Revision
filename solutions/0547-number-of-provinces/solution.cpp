class Solution {
private:
    void dfs(int node, vector<vector<int>>& list, vector<int>& vis) {
        vis[node] = 1;
        for(auto it : list[node]) {
            if(!vis[it]) {
                dfs(it, list, vis);
            }   
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> list(v);
        for(int i = 0; i<v; i++) {
            for(int j = 0; j<v; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    list[i].push_back(j);
                    list[j].push_back(i);
                }
            }
        }
        vector<int> vis(v, 0);
        int count = 0;
        for( int i = 0; i<v; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, list, vis);;
            }
        }
        return count;
    }
};
