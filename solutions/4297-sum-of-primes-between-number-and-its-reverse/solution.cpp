class Solution {
private:
    bool isprime(int num) {
        if(num < 2) return false;
        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0) return false;
        }
        return true;
    }
public:
    int sumOfPrimesInRange(int n) {
        int rev = 0;
        int original = n;
        int sum = 0;

        while(n>0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }
        int low = min(original, rev);
        int high = max(original, rev);
        for(int i = low; i<=high; i++) {
            if(isprime(i))
            {
                sum += i;
            }
        }
        return sum;
    }
};
