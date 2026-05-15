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
    int goodNodes(TreeNode* root) {
        int ans=0;
        dfs(root, INT_MIN, ans);
        return ans;
    }

    void dfs(TreeNode* node, int maxi, int& ans) {
        if(!node) return;

        if(maxi <= node->val)  {
            ans++;
            maxi = node->val;
        }

        dfs(node->left, maxi, ans);
        dfs(node->right, maxi, ans);
    }
};
