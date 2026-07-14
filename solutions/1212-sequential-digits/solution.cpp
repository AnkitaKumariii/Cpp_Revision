class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        queue<int>q;
        for(int i = 1; i < 10; i++) {
            q.push(i);
        }
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            if(n>high) continue;
            if(low <= n && n <= high) result.push_back(n);
            int lastDigit = n % 10;
            if(lastDigit < 9) {
                q.push(n * 10 + lastDigit + 1);
            }
        }
        return result;
    }
};
