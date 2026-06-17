class Solution {
private:
    void recursion(int index, vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>&ds) {
        if(target == 0) {
        
            ans.push_back(ds);
            return;
        }
        for(int i = index; i<candidates.size(); i++) 
        {
            if(i>index && candidates[i] == candidates[i-1]) continue;
            if(i == candidates.size()) {
            return;
            }
            if(candidates[i] <= target) {
            ds.push_back(candidates[i]);
            recursion(i+1,candidates, target - candidates[i], ans, ds);
            ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        recursion(0, candidates, target, ans, ds);
        return ans;
    }
};




