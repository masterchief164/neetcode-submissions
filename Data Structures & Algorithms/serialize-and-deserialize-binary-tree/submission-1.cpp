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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> ans;
        serialize(ans, root);
        return join(ans, ',');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = split(data, ',');
        int i = 0;
        return deserialize(i, vals);
    }    

    void serialize(vector<string> &ans, TreeNode* node){
        if(!node){ 
            ans.push_back("N");
            return;
        }

        ans.push_back(to_string(node->val));
        serialize(ans, node->left);
        serialize(ans, node->right);
    }

    string join(vector<string> &ans, char del){
        if (ans.empty()) {
            return "";
        }
        string res = "";
        for (size_t i = 0; i < ans.size(); ++i) {
            res += ans[i];
            // Add the delimiter after each element except the last one
            if (i < ans.size() - 1) {
                res += del;
            }
        }
        return res;
    }

    vector<string> split(const string &s, char delim) {
        vector<string> elems;
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }

    TreeNode* deserialize(int &i, vector<string> &vals){
        if(vals[i] == "N"){
            i++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(vals[i++]));
        node->left = deserialize(i, vals);
        node->right = deserialize(i, vals);
        return node;
    }
};
