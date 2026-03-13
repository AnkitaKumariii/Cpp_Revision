class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int,int>mpp;
        mpp[0] = 1;
        int preSum = 0, cnt = 0;
        for(int i = 0; i<n; i++) {
            preSum += nums[i] % 2;
            int remove = preSum - k;
            if(mpp.find(remove) != mpp.end())
            cnt += mpp[remove];
            mpp[preSum] += 1;
        }
        return cnt;
    }
};
