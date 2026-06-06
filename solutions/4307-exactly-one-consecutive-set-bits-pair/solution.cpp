class Solution {
public:
    bool consecutiveSetBits(int n) {
        string a = "";
        while(n>0) {
            a = char((n%2) + '0') + a;
            n/=2;
        }
        int count = 0;
        for(int i = 0; i<a.size(); i++) {
            if(a[i] == '1' && a[i+1] == '1') count++;
        }
        return count == 1;
    }
};
