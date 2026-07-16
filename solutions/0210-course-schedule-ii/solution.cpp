class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses);
        vector<int>topo;
        queue<int>q;
        for(auto &it: prerequisites) {
            indeg[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0; i<numCourses; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            topo.push_back(n);

            for(int neigh: adj[n]) {
                if(indeg[neigh] > 0) {
                    indeg[neigh]--;
                    if(indeg[neigh] == 0) q.push(neigh);
                }
            }
        }
        if (topo.size() != numCourses) {
            return {};
        }
        return topo;
    }
};
