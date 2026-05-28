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
        if(root == NULL) {
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* newBalanceBST(int low, int high) {
        if(low>high) return NULL;
        int mid = low + (high - low)/2;
        TreeNode* root = new TreeNode(ans[mid]);
        root->left = newBalanceBST(low, mid - 1);
        root->right = newBalanceBST(mid + 1, high);

        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int n = ans.size();
        return newBalanceBST(0, n-1);
    }
};
