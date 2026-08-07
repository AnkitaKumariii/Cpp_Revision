class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();     
        if(stones[1] - stones[0] > 1) {
            return false;
        }  
        if(n == 2) return true;      
        vector<vector<bool>> dp(n, vector<bool>(n + 1, false)); 
        dp[0][0] = true;
        dp[1][1] = true; 
        for(int i = 2; i < n; i++) {
            for(int j = i - 1; j >= 0; j--) {
                int k = stones[i] - stones[j];   
                if(k > j + 1) {
                    break;
                }              
                if(dp[j][k-1] || dp[j][k] || dp[j][k+1]) {
                    dp[i][k] = true;    
                    if(i == n - 1) {
                        return true;
                    }
                }
            }
        }    
        return false;
    }
};
