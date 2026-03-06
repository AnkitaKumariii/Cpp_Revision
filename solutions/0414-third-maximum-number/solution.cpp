class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long firstMax = LONG_MIN, secondMax = LONG_MIN, thirdMax = LONG_MIN;

        for(int i = 0; i < n; i++) {

            if(nums[i] == firstMax || nums[i] == secondMax || nums[i] == thirdMax)
                continue;

            if(nums[i] > firstMax) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[i];
            }
            else if(nums[i] > secondMax) {
                thirdMax = secondMax;
                secondMax = nums[i];
            }
            else if(nums[i] > thirdMax) {
                thirdMax = nums[i];
            }
        }
        if(thirdMax == LONG_MIN) {
            return firstMax;
        }

        return thirdMax;
    }
};
