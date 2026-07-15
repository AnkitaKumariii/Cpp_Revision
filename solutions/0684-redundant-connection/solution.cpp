class DSU {
public:
    vector<int>parent;
    vector<int>rank;
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i = 1; i<n+1; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int u, int v) {
        int pu = parent[u];
        int pv = parent[v];
        if(pu == pv) return;
        if(rank[pu]>rank[pv]) {
            parent[pv] = pu;
            rank[pu]++;
        }
        else if(rank[pv]>rank[pu]) {
            parent[pu] = pv;
            rank[pv]++;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(int i = 0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if(dsu.find(u)==dsu.find(v)) return edges[i];
            dsu.Union(u, v);
        }
        return {};
    }
};
