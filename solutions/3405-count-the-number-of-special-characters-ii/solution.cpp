class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int count = 0;
        unordered_map<int, int>ump;
        for(int i = n-1; i>=0; i--) {
            if(int(word[i]) >= 97 && int(word[i]) <=122) {
                if(ump.find(word[i]) == ump.end()) {
                    ump[word[i]] = i;
                }
            }
        }
        for(int i = 0; i <n; i++) {
            if(int(word[i]) >= 65 && int(word[i]) <= 90) {
                if(ump.find(word[i]) == ump.end()) {
                    ump[word[i]] = i;
                }
            }
        }
        for(char c = 'a'; c <= 'z'; c++) {
            if(ump.find(c)!=ump.end()) {
                char upper = toupper(c);
                if(ump.find(upper)!=ump.end()) {
                    if(ump[c] < ump[upper]) count++;
                }
            }
        }
        return count;
    }
};
