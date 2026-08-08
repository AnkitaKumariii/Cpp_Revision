class Solution {
public:
    int houserob(vector<int>& nums, int st, int end) {
        int n = nums.size();
        vector<int>dp(n - 1);
        dp[0] = nums[st];
        dp[1] = max(nums[st], nums[st+1]);
        int j = 2;
        for(int i = st+2; i<=end; i++) {
            dp[j] = max(dp[j-1], dp[j-2] + nums[i]);
            j++;
        }
        return dp[n-2];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        return max(houserob(nums, 0, n-2), houserob(nums, 1, n-1));
    }
};
