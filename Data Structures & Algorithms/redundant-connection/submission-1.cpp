class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> par(n+1), rank(n+1,1);
        for(int i = 1;i<n+1;i++) {
            par[i] = i;
        }

        for(const auto edge: edges) {
            if(!uni(par, edge[0], edge[1], rank)){
                return edge;
            }
        }
        return {};

    }
private:
    int find(vector<int> &par, int n) {
        int p = par[n];

        while(par[p] != p) {
            par[p] = par[par[p]];
            p = par[p];
        }
        return p;
    }

    bool uni(vector<int> &par, int a, int b, vector<int> &rank) {
        int p1 = find(par, a);
        int p2 = find(par, b);

        if(p1 == p2) return 0;

        if(rank[p1] > rank[p2]){
            par[p2] = p1;
            rank[p1]+=rank[p1];
        } else {
            par[p1] = p2;
            rank[p2]+=rank[p1];
        }
        return 1;
    }

};
