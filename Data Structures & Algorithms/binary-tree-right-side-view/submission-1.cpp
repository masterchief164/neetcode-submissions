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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans, 0);
        return ans;
    }

    void dfs(TreeNode* node, vector<int> &ans, int depth) {
        if(!node) return;
        if(depth == ans.size())
            ans.push_back(node->val);
        dfs(node->right, ans, depth + 1);
        dfs(node->left, ans, depth + 1);
    }
};
