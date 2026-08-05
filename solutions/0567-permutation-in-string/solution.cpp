class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> ans1(26, 0), ans2(26, 0);
        for(int i = 0; i<s1.size(); i++) {
            ans1[s1[i] - 'a']++;
            ans2[s2[i] - 'a']++;
        }
        int matches = 0;
        for(int i = 0; i<26; i++) {
            if(ans1[i] == ans2[i]) {
                matches++;
            }
        }
        int l = 0;
        for(int r = s1.size(); r<s2.size(); r++) {
            if(matches == 26) return true;
            int index = s2[r] - 'a';
            ans2[index]++;
            if (ans1[index] == ans2[index])
                matches++;
            else if (ans1[index] + 1 == ans2[index])
                matches--;
            index = s2[l] - 'a';
            ans2[index]--;

            if(ans1[index] == ans2[index])
                matches++;
            else if(ans1[index] - 1 == ans2[index])
                matches--;

            l++;
        }
        return matches == 26;
    }
};
