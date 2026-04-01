class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) return pow(x, n);
        double ans = 0;
        ans = pow(x, n);
        return ans;
    }
};
