class Solution {
public:
    int maxProduct(int n) {
    vector<int> arr;
    while(n > 0) {
        arr.push_back(n % 10);
        n /= 10;
    }
    reverse(arr.begin(), arr.end());
    int n1 = arr.size();
    sort(arr.begin(), arr.end());
    return arr[n1-1]*arr[n1-2];
    }
};
