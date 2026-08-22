class Solution {
public:
    bool checkDivisibility(int n) {
        int product = 1;
        int sum = 0;
        int ans = n;
        while(n>0) {
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }
        int divisor = sum + product;
            if(divisor == 0) {
            return false;
        }
        return ans % divisor == 0;
    }
};
