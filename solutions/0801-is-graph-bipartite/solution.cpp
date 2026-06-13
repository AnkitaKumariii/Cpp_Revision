class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {  //color = 1 & color = 0
        int n = graph.size();
        vector<int> color(n, -1);  
        for(int i = 0; i < n; i++) {
            if(color[i] != -1) continue;
            queue<int> q;
            q.push(i); 
            color[i] = 0; 
            while(!q.empty()) {
                int node = q.front();   
                q.pop();
                for(auto it : graph[node]) {
                    if(color[it] == -1) { //adjacent node pe check karega
                        color[it] = !color[node];
                        q.push(it);
                    }
                    else if(color[it] == color[node]){ //agrr same color hua toh false return karega
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
