class Solution { 
public:
    int sumBase(int n, int k) {
        vector<int> arr;
        while(n > 0) {
            arr.push_back(n % k);
            n /= k;
        }
        reverse(arr.begin(), arr.end());
        int sum = 0;
        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
        }
        return sum;
    }
};
