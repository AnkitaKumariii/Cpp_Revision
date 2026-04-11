class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return -1;
        int ans = INT_MAX;
        unordered_map<int, vector<int>> ump;
        for (int i = 0; i<n; i++) {
            ump[nums[i]].push_back(i);
        }
        for (auto &it : ump) {
            vector<int> &v = it.second;
            for (int i = 0; i + 2 < v.size(); i++) {
                int j = i + 1;
                int k = i + 2;
                int dist = abs(v[i] - v[j]) + abs(v[j] - v[k]) + abs(v[k] - v[i]);
                ans = min(ans, dist);
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

