class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> ans(n,0);
        for(int i = 0;i<n;i++) {
            while(stk.size() && temperatures[i] > temperatures[stk.top()]) {
                int idx = stk.top();
                ans[idx]= i - idx;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};
