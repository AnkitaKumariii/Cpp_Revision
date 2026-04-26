class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<bool> valid(n, false);
        vector<int> ans;
        int maxi = nums[0];
        valid[0] = true;
        for(int i = 1; i<n; i++) {
            if(nums[i]>maxi) {
              valid[i] = true;
              maxi = nums[i];
            }
        }
        maxi = nums[n-1];
        valid[n-1] = true;
        for(int i = n-2; i>=0; i--) {
            if(nums[i]>maxi) {
                valid[i] = true;
                maxi = nums[i];
            }
        }
        for(int i = 0; i<n; i++) {
            if(valid[i]) ans.push_back(nums[i]);
        }
        return ans;
    }
};
