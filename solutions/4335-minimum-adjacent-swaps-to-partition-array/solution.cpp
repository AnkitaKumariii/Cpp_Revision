class Solution {
public:
    static const int MOD = 1e9 + 7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        long long ans = 0;
        long long L = 0, M =0, R = 0;
        for(int x : nums) {
            if(x < a) {
                ans += M + R;
                L++;
            }
            else if(x<=b) {
                ans += R;
                M++;
            }
            else {
                R++;
            }
            ans %= MOD;
        }
        return ans%MOD;
    }
};
