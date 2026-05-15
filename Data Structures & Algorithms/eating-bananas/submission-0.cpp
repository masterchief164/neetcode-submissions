class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(l<=r) {
            int m =  l + (r-l)/2;
            int time = calcTime(piles, m);
            if(time <= h) {
                ans = m;
                r = m -1;
            } else {
                l = m +1;
            }
        }
        return ans;
    }

    int calcTime(vector<int> &piles, int time) {
        int ans = 0;

        for(auto x: piles) {
            ans += (x + time-1)/time;
        }
        return ans;
    }
};
