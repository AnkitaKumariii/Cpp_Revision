class Solution {
public:
    int GCD(int a, int b) {
        while(b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd = n * n;
        int sumEven = n * (n + 1);
        return GCD(sumOdd, sumEven);
    }
};
