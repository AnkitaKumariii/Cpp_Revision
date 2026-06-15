class Solution {
private:
    void recursion(int index, vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>&ds) {
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
        if(index == nums.size()) {
            return;
        }
        if(nums[index] <= target) {
            ds.push_back(nums[index]);
            recursion(index, nums, target - nums[index], ans, ds);
            ds.pop_back();
        }
        recursion(index + 1, nums, target, ans, ds);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        recursion(0, candidates, target, ans, ds);
        return ans;
    }
};
