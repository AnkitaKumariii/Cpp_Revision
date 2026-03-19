class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1) return true;
        int low = 1; 
        int high = n/3;
        while(low <= high) {
            int mid = (low + high)/2;
            if(pow(3, mid) == n) return true;
            else if(pow(3, mid) > n) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};
