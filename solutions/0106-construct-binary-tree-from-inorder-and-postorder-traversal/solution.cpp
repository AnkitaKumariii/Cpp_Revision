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
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int>mp;
        int n = inorder.size();
        for(int i = 0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        return buildTree(inorder, 0, n-1, postorder, 0, n-1, mp);
    }
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int, int>&mp) {
        if(inStart > inEnd || postStart>postEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mp[root->val];
        int left = inRoot - inStart;

        root->left = buildTree(inorder, inStart , inRoot - 1, postorder, postStart, postStart + left - 1, mp);
        root->right = buildTree(inorder, inRoot + 1, inEnd, postorder, postStart + left, postEnd - 1, mp);
        return root;
    }
};
