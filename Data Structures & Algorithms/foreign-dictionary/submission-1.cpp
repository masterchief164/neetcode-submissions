class Solution {
public:
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> vis;
    string result;

    string foreignDictionary(vector<string>& words) {
        
        for(auto x: words){
            for(auto c: x){
                adj[c];
            }
        }

        for(int i = 1;i<words.size();i++){
            string w1 = words[i-1], w2 = words[i];
            int n = min(w1.size(), w2.size());
            
            if(w1.size() > w2.size() && w1.substr(0, n) == w2.substr(0, n)) 
                return "";
            
            for(int j=0;j<n;j++){
                if(w1[j]!=w2[j]){
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }
        
        for(auto x: adj){
            if(dfs(x.first)) 
                return "";
        }

        reverse(result.begin(), result.end());
        return result;
            
    }

    bool dfs(char c){
        
        if(vis.find(c) != vis.end()) return vis[c];

        vis[c] = 1;
        for(auto x: adj[c]){
            if(dfs(x)) return 1;
        }
        vis[c] = 0;
        result.push_back(c);
        return 0;

    }
};
