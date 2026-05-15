class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;

        for(int a: asteroids) {
            while(stk.size() && a < 0 && stk.back() > 0) {
                int diff = a + stk.back();
                if(diff < 0) {
                    stk.pop_back();
                } else if(diff == 0) {
                    a = 0;
                    stk.pop_back();
                } else {
                    a = 0;
                }
            }
            if(a != 0) {
                stk.push_back(a);
            }
        }
        return stk;
    }
};