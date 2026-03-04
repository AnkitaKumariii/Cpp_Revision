class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        vector<int> ans(n);
        
        for(int i = n-1 ; i>=0; i--) {
            int sum = digits[i] + carry;
            int digit = sum % 10;
            carry = sum / 10;

            ans[i] = digit;
            
        }
        if(carry!=0)
        ans.insert(ans.begin(), carry);  
        return ans;     
    }
      
};
