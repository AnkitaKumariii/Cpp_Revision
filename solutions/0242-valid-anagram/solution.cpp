class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int>ump1;
        unordered_map<char, int>ump2; 
        for(auto & element : s) {
            ump1[element]++;
        }
        for(auto & element : t) {
            ump2[element]++;
        }
        return ump1 == ump2;
    }
};
