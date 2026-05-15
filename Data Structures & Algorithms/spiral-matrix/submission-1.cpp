class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l = 0, d = n, t = 0, r = matrix[0].size();
        vector<int> ans;
        while(l<r && t < d){
            for(int i = l;i<r;i++){
                ans.push_back(matrix[t][i]);
            }
            t ++;
            for(int i = t;i<d;i++){
                ans.push_back(matrix[i][r-1]);
            }
            r--;
            if (!(l < r && t < d)) {
                break;
            }
            for(int i = r-1;i>=l;i--){
                ans.push_back(matrix[d-1][i]);
            }
            d--;
            for(int i = d-1;i>=t;i--){
                ans.push_back(matrix[i][l]);
            }
            l++;
        }
        return ans;
    }
};
