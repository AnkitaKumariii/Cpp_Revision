class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();
        int ans = 0;
        int mini = INT_MAX;
        for(int i = 0; i<n; i++) {
            if(capacity[i] >= itemSize && capacity[i] < mini) {
                mini = capacity[i];
                ans = i;
            }
        }
        if(mini == INT_MAX) return -1;
        return ans;
    }
};
