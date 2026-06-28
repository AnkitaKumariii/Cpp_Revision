class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        long long totalSum = 0;
        for(int i = 0; i<k; i++) {
            long long multiply = 1LL * mul - i;
            if(multiply > 1) {
                totalSum += 1LL * nums[i] * multiply;
            }
            else {
                totalSum += nums[i];
            }
        }
        return totalSum;
    }
};
