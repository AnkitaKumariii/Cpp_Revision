class Solution {
private:
    vector<int> getDivisorsExceptSelf(int n) {
    vector<int> divisors;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            if(i != n) divisors.push_back(i);
            if(n / i != i && n / i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}
public:
    bool checkPerfectNumber(int num) {
        vector<int> divisors = getDivisorsExceptSelf(num);
        int d = divisors.size();
        int sum = 0;
        for(int i = 0; i < d; i++) {
            sum += divisors[i];     
        }
        return sum == num;
    }
};
