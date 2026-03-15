class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int colIndex = 1; colIndex<=rowIndex; colIndex++) {
            ans = ans * (rowIndex - colIndex + 1);
            ans = ans/(colIndex);
            ansRow.push_back(ans);
        }
        return ansRow;
    }
};
