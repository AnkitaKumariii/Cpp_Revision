class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> ans;
        for (int i = 0; i<n; i++) {
            ans.insert(nums[i]);
            int rev = 0;
            int temp = nums[i];
            while (temp != 0) {
                int digit = temp % 10;
                rev = rev * 10 + digit;
                temp /= 10;
            }
            ans.insert(rev);
        }
        return ans.size();
    }
};
