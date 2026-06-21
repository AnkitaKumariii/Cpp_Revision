class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>&visited, vector<int>&pathVisited, vector<int>&check) {
        visited[node] = 1;
        pathVisited[node] = 1;
        check[node] = 0;
        for(auto it : graph[node]) {
            if(!visited[it]) {
                if(dfs(it, graph, visited, pathVisited, check)) {
                    check[node] = 0;
                    return true;
                }
            }
            else if(pathVisited[it]) {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVisited[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> safe;
        vector<int>visited(n, 0);
        vector<int>pathVisited(n, 0);
        vector<int>check(n, 0);
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                dfs(i, graph, visited, pathVisited, check);
            }
        }
        for(int i = 0; i<n; i++) {
            if(check[i] == 1) safe.push_back(i);
        }
        return safe;
    }
};
