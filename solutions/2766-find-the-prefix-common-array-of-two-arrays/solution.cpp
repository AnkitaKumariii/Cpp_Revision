class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_map<int, int>ump;
        vector<int> ans;
        int count = 0;
        for(int i = 0; i<n; i++) {
            ump[A[i]]++;
            if(ump[A[i]] == 2) {
                count++;
            }
            ump[B[i]]++;
            if(ump[B[i]] == 2) {
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
