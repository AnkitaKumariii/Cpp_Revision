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
    unordered_map<int, TreeNode*> ump;
    unordered_set<int> s;
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        for(auto & v : descriptions) {
            int parent = v[0];
            int child = v[1];
            s.insert(child);
            int left = v[2];
            if(ump.find(parent) == ump.end()) {
                ump[parent] = new TreeNode(parent);
            }
            if(ump.find(child) == ump.end()) {
                ump[child] = new TreeNode(child);
            }
            if(left) {
                ump[parent]->left = ump[child];
            }
            else {
                ump[parent]->right = ump[child];
            }
        }
        TreeNode* root;
            for(auto & v : descriptions) {
                if(s.find(v[0]) == s.end()) root = ump[v[0]];;
            }
        return root;
    }
};
