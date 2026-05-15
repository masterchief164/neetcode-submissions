class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size(), m = amt;
        vector<int> prev(amt + 1, amt + 1);
        vector<int> curr(amt + 1, amt + 1);

        curr[0] = 0;
        prev[0] = 0;

        for(int i = 1;i<n+1;i++) {
            for(int j = 1; j<m+1;j++) {
                if(coins[i-1] <= j)
                    curr[j] = min(1+curr[j-coins[i-1]], prev[j]);
                else
                    curr[j]= prev[j];
            }
            prev = curr;
        }

        return prev[amt] > amt ? -1: prev[amt] ;
    }
};
