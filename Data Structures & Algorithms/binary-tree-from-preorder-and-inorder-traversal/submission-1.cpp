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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> idx;
        int preIdx = 0;

        for(int i = 0;i<inorder.size();i++){
            idx[inorder[i]] = i;
        }
        int ps = 0;
        return dfs(preorder, idx, 0, inorder.size()-1, ps);
    }

    TreeNode* dfs(vector<int>& preorder, unordered_map<int, int> &idx, int l, int r, int &ps){
        if(l>r) return nullptr;

        int rootVal = preorder[ps++];
        TreeNode* root = new TreeNode(rootVal);

        int rootPo = idx[rootVal];
        root->left = dfs(preorder, idx, l, rootPo-1, ps);
        root->right = dfs(preorder, idx, rootPo+1, r, ps);

        return root;
    }

};
