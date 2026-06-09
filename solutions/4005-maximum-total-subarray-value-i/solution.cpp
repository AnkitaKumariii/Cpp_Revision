class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long maxi = nums.back();
        long long mini = nums[0];
        long long diff = maxi - mini;
        return k*diff;
    }
};
