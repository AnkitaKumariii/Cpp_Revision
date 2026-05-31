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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key) return deletekahelper(root);
        TreeNode* dummy = root;
        while(root) {
            if(root->val > key) {
                if(root->left != NULL && root->left->val == key) {
                root->left = deletekahelper(root->left);
                break;
                }
                else {
                   root = root->left;
                }
            }
            else {
                if(root->right != NULL && root->right->val == key) {
                root->right = deletekahelper(root->right);
                break;
            }
                else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode* deletekahelper(TreeNode* root) {
        if(!root->left) return root->right;
        else if(!root->right) return root->left;

        TreeNode* rightchild = root->right;
        TreeNode* lastright = findlastright(root->left);
        lastright->right = rightchild;
        return root->left;
    }
    TreeNode* findlastright(TreeNode* root) {
        if(root->right == NULL) return root;
        return findlastright(root->right);
    }
};
