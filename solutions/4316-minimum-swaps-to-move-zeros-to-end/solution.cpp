class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int i = 0;
        int j = n-1;
        while(i<j) {
            while(i<j && nums[i]!=0) i++;
            while(i<j && nums[j] == 0) j--;
            if(i<j) {
                swap(nums[i], nums[j]);
                count++;
                i++, j--;
            }
        }
        return count;
    }
};
