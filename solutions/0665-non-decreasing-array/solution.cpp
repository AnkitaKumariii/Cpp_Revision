class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i<n-1; i++) {
            if(nums[i] > nums[i+1]) {
                count++;
                if(i==0) nums[i] = nums[i+1];
                else if(i == n-2 && nums[n-2] > nums[n-1]) nums[n-2] = nums[n-1];
                else if(nums[i+1]>=nums[i-1]) nums[i] = nums[i+1];
                else  nums[i+1] = nums[i];
                if (count == 2) return false;
            }
        }
        return true;
    }
};
