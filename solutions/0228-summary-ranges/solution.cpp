class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n == 0) return ans;
        int LB = nums[0];
        for (int i = 0; i < n; i++) {
            if (i == n-1 || nums[i] + 1 != nums[i+1]) {
                if (LB == nums[i]) ans.push_back(to_string(LB));
                else ans.push_back(to_string(LB) + "->" + to_string(nums[i]));
                if (i < n-1) LB = nums[i+1];
            }
        }
        return ans;
    }
};
