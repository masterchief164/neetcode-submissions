class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> ans(n,0);
        for(int i = n-1;i>-1;i--) {
            while(stk.size() && temperatures[stk.top()] <= temperatures[i])
                stk.pop();
            if(!stk.size()) {
                ans[i] = 0;
                stk.push(i);
                continue;
            }
            ans[i] = stk.top() - i;
            stk.push(i);
        }
        return ans;
    }
};
