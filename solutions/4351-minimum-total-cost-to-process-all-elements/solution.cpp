class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        long long ans = k; 
        long long count = 0;
        long long totalCost = 0;
        for(int i = 0; i<n; i++) {
            if(ans < nums[i]) {
                long long req = nums[i] - ans;
                //short me 
                long long me = (req + k -1)/k;
                long long pichla = count;
                count += me;
                long long first = me;
                long long second = 2LL * pichla + me + 1;
                if(first%2 == 0) {
                    first /= 2;
                }
                else {
                    second /= 2;
                }
                long long add = ((first % MOD) * (second % MOD)) % MOD;
                totalCost = (totalCost + add) % MOD;
                ans += me * 1LL * k;
            }
            ans -=nums[i];
        }
        return totalCost%MOD;
    }
};
