class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return {0};
        vector<int> ans(n,0);
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                if(nums[i]%2 != 0 && nums[j]%2 == 0 || nums[i]%2 == 0 && nums[j]%2 != 0) {
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};
