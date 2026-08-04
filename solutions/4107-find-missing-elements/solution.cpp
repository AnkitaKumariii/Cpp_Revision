class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>ans;
        int min = nums[0];
        int max = nums[n-1];
        int j = 0;
        for(int i = min; i<=max; i++) {
            if(j<n && nums[j] == i) {
                j++;
            }
            else ans.push_back(i);
        }
        return ans;
    }
};
