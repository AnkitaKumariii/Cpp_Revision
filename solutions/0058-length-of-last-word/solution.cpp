class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int n = s.size()-1;
        while(s[n] == ' ') {
            n--;
        }
        while(n>=0 && s[n] != ' ') {
            count++;
            n--;
        }
        return count;
    }
};
