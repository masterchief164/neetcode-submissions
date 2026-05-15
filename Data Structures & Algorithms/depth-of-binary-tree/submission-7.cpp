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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 1});
        int ans = 0;

        while(stk.size()){
            pair<TreeNode*, int> curr = stk.top();
            TreeNode* node = curr.first;
            stk.pop();
            if(curr.first){
                ans = max(ans, curr.second);
                stk.push({curr.first->left, curr.second +1});
                stk.push({curr.first->right, curr.second+1});
            }
        }
        return ans;
    }
};
