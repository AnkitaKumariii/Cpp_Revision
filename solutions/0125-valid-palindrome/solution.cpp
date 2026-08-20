class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n-1;
        while(l<r) {
            while(l < r && !isalnum(s[l])) {
                l += 1;
            }
            while(r > l && !isalnum(s[r])) {
                r -= 1;
            }
            if(tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l = l+1, r = r-1;
        }
        return true;
    }
};
