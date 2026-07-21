class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0, high = rows - 1;
        while (low <= high) {
            int mid = (low +high) / 2;
            if(target > matrix[mid][cols - 1]) {
                low = mid + 1;
            }
            else if(target < matrix[mid][0]) {
                high = mid - 1;
            }
            else {
                break;
            }
        }

        if(!(low<=high))
            return false;
        int mid = (low + high) / 2;
        int l = 0, r = cols - 1;
        while(l <= r) {
            int mid2 = (l + r) / 2;
            if(target > matrix[mid][mid2]) {
                l = mid2 + 1;
            }
            else if(target < matrix[mid][mid2]) {
                r = mid2 - 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
