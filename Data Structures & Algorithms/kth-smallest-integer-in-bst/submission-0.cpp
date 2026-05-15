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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans(2);
        ans[1] = k;
        dfs(root, ans);
        return ans[0];
    }
    void dfs(TreeNode* node, vector<int> &ans){
        if(!node) return;
        dfs(node->left, ans);
        ans[1]--;
        if(ans[1] == 0){
            ans[0] = node->val;
            return;
        }
        dfs(node->right, ans);
    }
};
