class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>> ans = occupiedIntervals;
        int n = ans.size();
        vector<vector<int>>merge, result;
        sort(ans.begin(), ans.end());
        for(auto & it : ans) {
            if(merge.empty() || merge.back()[1] + 1 < it[0]) {
                merge.push_back(it);
            }
            else {
                merge.back()[1] = max(merge.back()[1], it[1]);
            }
        }
        for(auto & it : merge) {
            int i = it[0];
            int j = it[1];
            if(j<freeStart || i>freeEnd) {
                result.push_back(it);
            }
            else {
                if(i<freeStart) result.push_back({i, freeStart - 1});
                if(j>freeEnd) result.push_back({freeEnd + 1, j});
            }
        }
        return result;
    }
};
