/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mp;
        void dfs(TreeNode* root, int row, int col) {
            if(root == NULL) return;
            mp[col][row].insert(root->val);
            if(root->left) dfs(root->left,row + 1, col - 1);
            if(root->right) dfs(root->right,row + 1, col + 1);
        }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        for(auto &colPair : mp) {
            vector<int> col;
            for(auto &rowPair : colPair.second) {
                for(auto value : rowPair.second) {
                    col.push_back(value);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};
