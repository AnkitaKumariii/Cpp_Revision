class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int>ump;
        int index = 0;
        int n = strs.size();
        vector<vector<string>>ans;
        for(int i = 0; i<n; i++) {
            string curr = strs[i];
            sort(curr.begin(), curr.end());
            if(ump.find(curr) == ump.end()) { 
                ump[curr] = index;
                ans.push_back({});
                ans[index].push_back(strs[i]);
                index++;
            }
            else {
                ans[ump[curr]].push_back(strs[i]);
            }
        }  
        return ans;
    }
};



