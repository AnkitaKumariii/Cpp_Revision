class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();    
        int maxi = INT_MIN, mini = INT_MAX;
        int max_index = 0, min_index = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                max_index = i;
            }
            if(nums[i] < mini) {
                mini = nums[i];
                min_index = i;
            }
        }
        int left = min(min_index, max_index);
        int right = max(min_index, max_index);
        return min({right + 1, n - left, (left + 1) + (n - right)});
    }
};
