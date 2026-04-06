class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int product = 1;
        int Result = 0;
        vector<int> arr;
        while(n > 0) {
            arr.push_back(n % 10);
            n /= 10;
        }
        reverse(arr.begin(), arr.end());
        for(int i = 0; i<arr.size(); i++) {
            sum += arr[i];
            product *= arr[i];
            Result = product - sum;
        }
        return Result;
    }
};
