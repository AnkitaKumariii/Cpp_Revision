class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());
        int n = nums1.size();
        int Shubham = nums1[0]%2 == 0;
        if(Shubham) {
            for(int i = 0; i<n;i++) {
                if(nums1[i]%2 != 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
