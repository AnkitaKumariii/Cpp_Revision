class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 0;
        int j = 1;
        int ans = 0;
        while(i<n && j<n) {
            if(prices[i]>=prices[j]) {
                i = j;
                j++;
            }
            else {
                ans = max(prices[j]-prices[i], ans);
                j++;
            }

        }
        return ans;
    }
};
