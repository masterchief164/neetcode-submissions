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
       unordered_map<int,int> mp;

       for(int i = 0;i<inorder.size();i++) {
        mp[inorder[i]] = i;
       }

       int ps = 0;
       return dfs(preorder, inorder, mp, 0, inorder.size()-1, ps);
    }

    TreeNode* dfs(vector<int>& pre, vector<int>& ino, unordered_map<int,int>& mp, int l, int r, int &p) {
        if(l>r) return nullptr;

        TreeNode* root = new TreeNode(pre[p]);
        int inPo = mp[pre[p++]];

        root->left = dfs(pre, ino, mp, l, inPo-1, p);
        root->right = dfs(pre, ino, mp, inPo+1, r, p);

        return root;
    }

};
