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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }


    void dfs(TreeNode* root) {
        if(!root) return;
        int l = getMax(root->left);
        int r = getMax(root->right);

        ans = max(ans, root->val+l+r);
        dfs(root->left);
        dfs(root->right);
    }

    int getMax(TreeNode* root){
        if(!root) return 0;

        int l = getMax(root->left);
        int r = getMax(root->right);

        int path = root->val + max(l, r);
        return max(0, path);
    }
};
