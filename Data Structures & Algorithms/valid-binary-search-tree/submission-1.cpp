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
        vector<int> vals;
        dfs(root, vals);
        return isSorted(vals);
    }

    void dfs(TreeNode* node, vector<int>& vals){
        if(!node)
            return;
        
        dfs(node->left, vals);
        vals.push_back(node->val);
        dfs(node->right, vals);
    }


    bool isSorted(vector<int> & vals){
        for(int i = 0;i<vals.size()-1; i++){
            if(vals[i] >= vals[i+1]) return 0;
        }
        return 1;
    }
};
