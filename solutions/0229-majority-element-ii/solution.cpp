class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int element1 = 0, element2 = 0;

        
        for(int i = 0; i < n; i++) {
            if(cnt1 == 0 && nums[i] != element2) {
                element1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && nums[i] != element1) {
                element2 = nums[i];
                cnt2 = 1;
            }
            else if(nums[i] == element1) {   
                cnt1++;
            }
            else if(nums[i] == element2) {
                cnt2++;
            }
            else {
                cnt1--, cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] == element1) cnt1++;
            else if(nums[i] == element2) cnt2++;
        }

        vector<int> ans;
        
        if(cnt1 > n/3) ans.push_back(element1);
        if(cnt2 > n/3) ans.push_back(element2);

        return ans;
        
    }
};
