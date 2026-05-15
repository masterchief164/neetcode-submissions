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
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        return dfs(root)[1];
    }

    vector<int> dfs(TreeNode* root) {
        if(!root) return {0,1};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        return {1+max(left[0], right[0]), abs(left[0]-right[0]) <2 && left[1] && right[1]};
    }
};
