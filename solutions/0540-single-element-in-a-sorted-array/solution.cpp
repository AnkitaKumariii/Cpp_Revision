class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if ( n==1 || nums[0] != nums[1]) return nums[0];
        int low = 0;
        int high = n - 1;

        while(low <= high) {
            int mid = (low + high)/2;
            if( nums[mid-1] != nums[mid] && nums[mid+1]!=nums[mid]) {
                return nums[mid];
            }
            else if(mid%2 == 0 && nums[mid+1] == nums[mid] || mid%2 != 0 && nums[mid-1] == nums[mid]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return nums[low];
    
        
    }
};
