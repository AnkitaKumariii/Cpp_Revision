class Solution {
private:
    vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int>stk;
        for(int i = n-1; i>=0; i--) {
            while(!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            nse[i] = stk.empty() ? n : stk.top(); 
            stk.push(i);
        }
        return nse;
    }
    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int>stk;
        for(int i = 0; i<n; i++) {
            while(!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            psee[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        return psee;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        long long total = 0;
        int mod = (int)(1e9+7);
        for(int i = 0; i<n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            total = (total + (left * right * 1LL * arr[i]) % mod) % mod;
        }
        return total;
    }
};
