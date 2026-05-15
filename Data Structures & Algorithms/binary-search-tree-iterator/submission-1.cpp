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
class BSTIterator {
    private:
    stack<TreeNode*> stk;
    TreeNode* curr;
public:
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        while(curr){
            stk.push(curr);
            curr = curr->left;
        }

        TreeNode* res = stk.top();
        stk.pop();

        TreeNode* curr = res->right;
        while(curr) {
            stk.push(curr);
            curr = curr->left;
        }

        return res->val;
    }
    
    bool hasNext() {
        return stk.size() || curr;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */