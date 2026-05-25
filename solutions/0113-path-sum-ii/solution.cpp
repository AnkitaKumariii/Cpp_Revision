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
    void dfs(TreeNode* root, int neededSum, vector<vector<int>>& ans, vector<int>& aam) {
        if(root == NULL) return;
        aam.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            if(root->val == neededSum) {
                ans.push_back(aam);
            }
        }
        dfs(root->left, neededSum - root->val, ans, aam);
        dfs(root->right, neededSum - root->val, ans, aam);
        aam.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>aam;
        dfs(root, targetSum, ans, aam);
        return ans;
    }
};

