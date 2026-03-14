class Solution {
public:
    int mirrorDistance(int n) {
        int temp = 0;
        int k = n;
        while(n != 0) {
        int digit = n % 10;
        temp = temp * 10 + digit;
        n /= 10;
        
        }
        return abs(k-temp);
    }   

};
