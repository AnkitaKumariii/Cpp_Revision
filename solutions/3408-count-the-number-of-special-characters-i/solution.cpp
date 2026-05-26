class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        int count = 0;
        for(int i = 0; i<n; i++) {
            char c = word[i];
            if(c>='a' && c<='z') {
                lower[c-'a'] = 1;
            }
            else {
                upper[c-'A'] = 1;
            }
        }
        for(int i = 0; i<26; i++) {
            if(lower[i] && upper[i]) count++;
        }
        return count;
    }
};
