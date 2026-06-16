class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        unordered_map<int,vector<int>> graph;
        for(int i = 0; i<dislikes.size(); i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(n+1, 0);
        for(int i = 1; i <= n; i++) {
            if(color[i] != 0) continue;
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(int neigh : graph[node]) {
                    if(color[neigh] == 0) {
                        color[neigh] = -color[node];
                        q.push(neigh);
                    }
                    else if(color[neigh] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
