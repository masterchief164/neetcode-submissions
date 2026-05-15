class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0, n = heights.size();
        vector<int> left(n, -1), right(n,n);

        stack<int> stk;

        for(int i=0;i<n;i++){
            while(stk.size() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }
            if(stk.size()){
                left[i] = stk.top();
            }
            stk.push(i);
        }

        stk = {};

        for(int i = n-1; i>=0;i--) {
            while(stk.size() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }

            if(stk.size()){
                right[i] = stk.top();
            }
            stk.push(i);
        }

        for(int i = 0;i<n;i++) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }

        return ans;
    }
};
