class Solution {
public:
    int passwordStrength(string password) {
        int n = password.size();
        int ans = 0;
        unordered_set<char> ust;
        for(int i = 0; i<n; i++) {
            ust.insert(password[i]);
        }
        for(auto it = ust.begin(); it != ust.end(); it++) {   
            char c = *it;
            if(c>='a' && c<='z') {
                ans += 1;
            }
            else if(c>='A' && c<='Z') {
                ans += 2;
            }
            else if(c>='0' && c<='9') {
                ans += 3;
            }
            else if(c == '!' || c == '@' || c == '#' || c == '$') {
                ans += 5;
            }
        }
        return ans;
    }
};
