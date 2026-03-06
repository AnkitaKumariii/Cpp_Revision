class Solution {
public:
    int mySqrt(int x) {
        int low = 1, high = x/2;
        if(x==1) {
            return 1;
        }
        while(low <= high) {
            long long mid = (low+high)/2;
            if(x == mid*mid) {
                return mid;
            }
            else if(x>mid*mid) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }
};
