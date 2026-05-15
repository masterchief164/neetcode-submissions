/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> oldToNew;
        Node* curr = head;
        while(curr) {
            Node* currCopy = oldToNew[curr];
            if(!currCopy) {
                currCopy = new Node(curr->val);
                oldToNew[curr] = currCopy;
            }
            currCopy->val = curr->val;
            Node* next = curr->next;
            if(curr->next){
                Node* nextNew = oldToNew[next];
                if(!nextNew) {
                    nextNew = new Node(next->val);
                    oldToNew[next] = nextNew;
                }
                currCopy->next = nextNew;
            }
            if(curr->random) {
                Node* rand = oldToNew[curr->random];
                if(!rand) {
                    rand = new Node(curr->random->val);
                    oldToNew[curr->random] = rand;
                }
                currCopy->random = rand;
            }
            curr = curr->next;
        }
        return oldToNew[head];
    }
};
