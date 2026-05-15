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
    bool isValidBST(TreeNode* root) {
        return isValid(root, INT_MIN, INT_MAX);
    }

    bool isValid(TreeNode* node, int left, int right){
        if(!node) return 1;
        int curr = node->val;
        
        if(!(left< curr && right> curr)) return 0;

        return isValid(node->left, left, node->val) && isValid(node->right, node->val, right);
    }
};
