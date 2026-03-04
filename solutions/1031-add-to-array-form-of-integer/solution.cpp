class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int i = num.size() - 1;
        int carry = k;

        while(i >= 0 || carry > 0) {
            if(i >= 0) {
                carry += num[i];
                i--;
            }

            ans.push_back(carry % 10);
            carry /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
