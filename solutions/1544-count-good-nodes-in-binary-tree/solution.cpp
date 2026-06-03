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
    int count = 0;
    void dfs(TreeNode* root, int maxVal) {
        if(!root) return;
        if(root->val >= maxVal) {
            maxVal = max(maxVal, root->val);
            count++;
        }
        dfs(root->left, maxVal);
        dfs(root->right, maxVal);
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return count;
    }
};
