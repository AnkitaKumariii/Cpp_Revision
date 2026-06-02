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
    vector<int> ans;
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root);
        int sum = 0;
        int n = ans.size();
        for(int i = 0; i<n; i++) {
            if(ans[i] >= low && ans[i] <= high) {
                sum += ans[i];
            }
        }
        return sum;
    }
};
