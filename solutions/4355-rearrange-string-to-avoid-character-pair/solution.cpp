class Solution {
public:
    bool valid(string &s, char x, char y) {
        bool seen = false;
        for(char c: s) {
            if(c == x) seen = true;
            if(c == y && seen) return false;
        }
        return true;
    }
    string rearrangeString(string s, char x, char y) {
        string first = "", middle = "", last = "";

        for(char c: s) {
            if(c == y) {
                first += c;
            }
            else if(c == x) {
                last += c;
            }
            else {
                middle += c;
            }
        }
        return first+middle+last;
    }
};
