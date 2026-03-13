class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        mpp[0] = 1;
        int preSum = 0, cnt = 0;
        for(int i = 0; i<n; i++) {
            preSum += nums[i];
            int remove = preSum - goal;
            cnt += mpp[remove];
            mpp[preSum] += 1;
        }
        return cnt;
    }
};
