class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int r = 0, l = 0;
        int min_length = INT_MAX;
        int sum = 0;
        while(r<n) {
            sum += nums[r];
            while(sum>=target) {
                int len = r - l + 1;
                min_length = min(min_length, len);
                sum -=nums[l];
                l++;
            }
            r++;
        }
        if(min_length == INT_MAX) return 0;
        return min_length;
    }
};
