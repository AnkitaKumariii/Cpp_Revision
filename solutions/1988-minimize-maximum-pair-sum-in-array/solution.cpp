class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxi = INT_MIN;
        int sum = 0;
        int i = 0;
        int j = n - 1;
        while(i<j) {
            sum = nums[i] + nums[j];
            maxi = max(maxi, sum);
            i++;
            j--;
        }
        return maxi;
    }
};
