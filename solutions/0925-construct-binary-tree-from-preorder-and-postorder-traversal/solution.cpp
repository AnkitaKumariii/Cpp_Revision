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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        map<int, int>mp;
        int n = postorder.size();
        for(int i = 0; i<n; i++) {
            mp[postorder[i]] = i;
        }
        return buildTree(preorder, 0, n-1, postorder, 0, n-1, mp);
    }
    TreeNode* buildTree(vector<int>& pre, int preStart, int preEnd, vector<int>& post, int postStart, int postEnd, map<int, int>&mp) {
        if(preStart > preEnd || postStart > postEnd) return NULL;
        TreeNode* root = new TreeNode(pre[preStart]);
        if(preStart == preEnd) return root;
        int leftRoot = pre[preStart + 1];
        int index = mp[leftRoot];
        int left = index - postStart + 1;

        root->left = buildTree(pre, preStart + 1, preStart + left, post, postStart, index, mp);
        root->right = buildTree(pre, preStart + left + 1, preEnd,post, index + 1, postEnd-1, mp);
        return root;
    }
};
