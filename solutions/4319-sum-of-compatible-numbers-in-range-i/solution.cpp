class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans = 0;
        int i = max(1, n - k);
        int j = n + k;
        while(i<=j) {
            if((n & i) == 0) {
                ans = ans + i;
            }
            if(i != j && (n & j) == 0) {
                ans = ans + j;
            }
            i++;
            j--;
        }
        return ans;
    }
};
