class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum1 = 0;
        int sum2 = 0;
        int ans = 0;
        for(int i = 0; i<n+1; i++) {
            if(i%m != 0) sum1 += i;
            if(i%m == 0) sum2 += i;
            ans = sum1 - sum2;
        }
        return ans;
    }
};
