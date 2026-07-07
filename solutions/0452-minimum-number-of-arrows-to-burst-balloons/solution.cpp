class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int n = points.size();
        if(n == 0) return 0;
        int count = 1;
        int mini = points[0][1];
        for(int i = 0; i<n; i++) {
            if(points[i][0] > mini) {
                count++;
                mini = points[i][1];
            }
            else {
                mini = min(mini, points[i][1]);
            }
        }
        return count;
    }
};
