class Solution {
    public int largestRectangleArea(int[] heights) {
        int ans = 0, n = heights.length;
        int[][] nse = new int[n][2];
        Stack<Integer> stk = new Stack<>();
        stk.push(0);
        nse[0][0] = -1;

        for(int i = 1;i<n;i++) {
            while(!stk.isEmpty() && heights[i] <= heights[stk.peek()]) {
                stk.pop();
            }
            if(!stk.isEmpty()) {
                nse[i][0] = stk.peek();
            } else {
                nse[i][0] = -1;
            }
            stk.push(i);
        }

        stk.clear();
        nse[n-1][1] = n;
        for(int i = n-1;i>=0;i--) {
            while(!stk.isEmpty() && heights[i] <= heights[stk.peek()]) {
                stk.pop();
            }

            if(!stk.isEmpty()) {
                nse[i][1] = stk.peek();
            } else {
                nse[i][1] = n;
            }

            stk.push(i);
        }

        for(int i = 0;i<n;i++) {
            int tmp = heights[i] * (nse[i][1]-nse[i][0]-1);
            ans = Math.max(tmp, ans);
        }

        return ans;
    }
}
