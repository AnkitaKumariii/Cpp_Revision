class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n-1;
        int cnt = 0;
        while(i<j) {
            if(nums[i] + nums[j] < target) {
                cnt += (j-i);
                i++;
            }
            else {
                j--;
            }
        }
        return cnt;
    }
};
