/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> oldToNew;
        return helper(node, oldToNew);
    }

    Node* helper(Node* curr, map<Node*, Node*> &oldToNew){
        if(!curr) return nullptr;

        if(oldToNew[curr]) return oldToNew[curr];

        Node* newNode = new Node(curr->val);
        oldToNew[curr] = newNode;

        for(Node* node: curr->neighbors){
            newNode->neighbors.push_back(helper(node, oldToNew));
        }
        return newNode;
    }
};
