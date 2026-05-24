class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> ump;
        vector<int> ans;
        for(int i = 0; i<n; i++) {
            if(ump[nums[i]] < k) {
                ans.push_back(nums[i]);
                ump[nums[i]]++;
            }
        }
        return ans;
    }
};
