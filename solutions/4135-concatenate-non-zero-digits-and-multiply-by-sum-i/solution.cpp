class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 0) return 0;
        long long x = 0;
        int sum = 0;
        vector<int> digits;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                digits.push_back(digit);
                sum += digit;
            }
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        for (int d : digits) {
            x = x * 10 + d;
        }
        return x * sum;
    }
};
