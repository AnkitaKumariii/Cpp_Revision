class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        int leftsum= 0;
        int rightsum = (n*(n+1))/2;
        for(int i = 1; i<n; i++) {
            leftsum = leftsum + i;
            if(i != 1) rightsum = rightsum - (i - 1);
            if(leftsum == rightsum) {
                return i;
            }
        }
        return -1;
    }
};
