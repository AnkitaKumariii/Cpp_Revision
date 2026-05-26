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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool LeftToRight = true;
        while(!q.empty()) {
            int n = q.size();
            vector<int> row(n);
            for(int i = 0; i<n; i++) {
                TreeNode* root = q.front();
                q.pop();

                int index = 0;
                if(LeftToRight) {
                    index = i;
                }
                else {
                    index = n - 1 - i;
                }

                row[index] = root->val;
                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);
            }
            LeftToRight = !LeftToRight;
            result.push_back(row);
        }
        return result;
    }
};
