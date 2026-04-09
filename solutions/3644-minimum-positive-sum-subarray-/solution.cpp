class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        int i = 0; 
        int j = 0;
        while(i < n) {
            j = i;
            int sum = 0;
            while(j < n) {
                sum += nums[j];
                int len = j - i + 1;
                if(len >= l && len <= r && sum > 0) {
                    ans = min(ans, sum);
                }
                if(len == r) break;
                j++;
            }
            i++;
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
