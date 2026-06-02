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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root) {
        if(!root) return;

        inorder(root->left);
        if(prev != NULL && (root->val < prev->val)) {

            //If this is first violation, mark these two nodes as first and middle
            if(first == NULL) {
                first = prev;
                middle = root;
            }
            //If this is second one, mark these as last
            else {
                last = root;
            }
        }
        prev = root; //mark these node as prev
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};
