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
        TreeNode* curr = root;
        while(curr){
            if(curr->left == nullptr){
                k--;
                if(k == 0) return curr->val;
                curr = curr->right;
            } else {
                TreeNode* next = curr -> left;
                while(next->right && next->right !=curr) {
                    next = next->right;
                }
                if(next->right) {
                    next ->right = nullptr;
                    k--;
                    if(!k) return curr->val;
                    curr = curr ->right;
                } else {
                    next->right = curr;
                    curr = curr->left;
                }
            }
        }
        return -1;
    }
};
