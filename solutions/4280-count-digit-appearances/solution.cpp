class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int count = 0;
        int Sh = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] == 0 && digit == 0) {
                count++;
            }
            Sh = nums[i];
            while(Sh>0) {
                if(Sh%10 == digit) {
                    count++;
                }
                Sh /= 10;
            }
        }
        return count;
    }
};
