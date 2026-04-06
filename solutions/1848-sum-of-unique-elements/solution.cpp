class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < n; i++) {
            bool Left  = (i == 0)     || (nums[i] != nums[i-1]);
            bool Right = (i == n - 1) || (nums[i] != nums[i+1]);
            if (Left && Right) {
                sum += nums[i];
            }
        }
        return sum;
    }
};
