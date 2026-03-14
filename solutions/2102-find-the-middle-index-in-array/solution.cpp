class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n);
        vector<int>right(n);
        
        int preSum = 0, postSum = 0;
        for(int i = 1; i<n; i++) {
            preSum += nums[i-1];
            left[i] = preSum;
        }
        for(int i = n-1; i>=1; i--) {
            postSum += nums[i];
            right[i-1] = postSum;
        }
        for(int i = 0; i<n; i++) {
            if(left[i] == right[i]) 
            return i;
        }
        return -1;
    }
};
