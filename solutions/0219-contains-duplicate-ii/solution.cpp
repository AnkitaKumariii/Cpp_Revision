class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> ump;
        for(int i = 0; i<n; i++){
            if(ump.find(nums[i]) != ump.end()) {
                if(i-ump[nums[i]] <= k) return true;
            }
            ump[nums[i]] = i;
        }
        return false;
    }
};
