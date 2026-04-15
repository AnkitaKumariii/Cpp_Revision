class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++) {
            if(nums[i] + nums[i+1] > nums[i+2]) {
                int perimeteroftriangle = nums[i] + nums[i+1] + nums[i+2];
                maxi = max(maxi, perimeteroftriangle);
            }
        }
        return maxi;
    }
};
