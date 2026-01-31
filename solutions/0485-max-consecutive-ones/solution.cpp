class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int count = 0;
        int countMax = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1)
            {
                count++;
                countMax = max(countMax, count);
            }
            else {
                count = 0;
            }
        }
        return countMax;
    
    }
};
