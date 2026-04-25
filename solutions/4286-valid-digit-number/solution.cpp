class Solution {
public:
    bool validDigit(int n, int x) {
        int shubham = n;
        while(shubham >= 10) {
            shubham/=10;
        }
        if(shubham == x) return false;
        
        while(n>0) {
            int digit = n%10;
            if(digit == x) return true;
            n = n/10;
        }
        return false;
    }
};
