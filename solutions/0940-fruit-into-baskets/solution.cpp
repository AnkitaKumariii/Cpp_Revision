class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k = 2;
        int n = fruits.size();
        unordered_map<int, int> ump;
        int maxlen = 0; 
        int l = 0, r = 0;   
        while(r<n) {
            ump[fruits[r]]++;
            while(ump.size() > k) {
                ump[fruits[l]]--;
                if(ump[fruits[l]] == 0) {
                    ump.erase(fruits[l]);
                }
                l++;
            }
            if(ump.size() <= k) {
                maxlen = max(maxlen, r-l+1);
                r++;
            }
        }
        return maxlen;
    }
};
