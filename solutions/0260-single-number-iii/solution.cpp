class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long XOR = 0;
        for(int i = 0; i<n; i++) {
            XOR = XOR^nums[i];
        }
        long long rightmost = XOR & (-XOR); //invert of 2 = 1101 + 1 = 1110  
        int b1 = 0;                          // now we have 0010 & 1110 = 0010
        int b2 = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] & rightmost) b1 = b1^nums[i];
            else b2 = b2^nums[i];
        }
        return {b1, b2};
    }
};
