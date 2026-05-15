class TrieNode {
    public:
        unordered_map<char, TrieNode*> next;
        bool end;
};


class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto x: word){
            if(curr->next.find(x) == curr->next.end()){
                curr->next[x] = new TrieNode();
            }
            curr = curr->next[x];
        }
        curr->end = 1;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(auto x: word) {
            if(curr->next.find(x) == curr->next.end()){
                return 0;
            }
            curr = curr->next[x];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(auto x: prefix) {
            if(curr->next.find(x) == curr->next.end()){
                return 0;
            }
            curr = (curr->next)[x];
        }
        return 1;
    }
};
