class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num/2;
        if(num == 1) {
            return true;
        }
        while(low <= high) {
            long long mid = (low+high)/2;
            if(num == mid*mid) {
                return true;
            }
            else if(num > mid*mid) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }

        }
        return false;
    }
};
