class Solution {
private:
    void recursion(vector<int>& ans1, vector<int>& nums, vector<vector<int>> &ans, int freq[]) {
        int n  = nums.size();
        if(ans1.size() == nums.size()) {
            ans.push_back(ans1);
            return;
        }
        for(int i = 0; i<n; i++) {
            if(!freq[i]) {
                ans1.push_back(nums[i]);
                freq[i] = 1;
                recursion(ans1, nums, ans, freq);
                freq[i] = 0;
                ans1.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n  = nums.size();
        vector<vector<int>> ans;
        vector<int>ans1;
        int freq[n];
        for(int i = 0; i<n; i++) {
            freq[i] = 0;
        }
        recursion(ans1, nums, ans, freq);
        return ans;
    }
};
