class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MAX;
        long long sum1 = nums[0];
        long long sum2 = nums[n-1];
        for(int i = 1; i<n-1; i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]);
            else if(nums[i] > nums[i-1]) sum1+=nums[i];
            else sum2+=nums[i];
        }
        if(sum1 > sum2) return 0;
        else if(sum1 < sum2) return 1;
        else return -1;
    }
};
