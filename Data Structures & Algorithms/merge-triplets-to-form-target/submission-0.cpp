class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> avail;

        for(auto x: triplets) {
            if(x[0] > target[0] || x[1] > target[1] || x[2] > target[2]) {
                continue;
            }
            for(int i = 0;i<3;i++) {
                if(x[i] == target[i]) avail.insert(i);
            }
        }
        return avail.size() == 3;
    }
};
