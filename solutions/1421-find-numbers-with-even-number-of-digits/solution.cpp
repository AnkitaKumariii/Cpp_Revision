class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i<n; i++) {
            int num = nums[i];
            int digits = 0;
            while(num > 0) {
                num /= 10;
                digits++;
            }
            if(digits%2 == 0) {
                count++;
            }
        }
        return count;
    }
};
