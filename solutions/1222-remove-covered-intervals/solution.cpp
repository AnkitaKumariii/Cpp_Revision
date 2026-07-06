class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int n = intervals.size();
        int count = 0;
        int maxi = 0;
        for(auto &it : intervals) {
            if(it[1] > maxi) {
                count++;
                maxi = it[1];
            }
        }
        return count;
    }
};
