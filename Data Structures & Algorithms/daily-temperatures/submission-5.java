class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> stk = new Stack<>();
        int n = temperatures.length;
        int[] ans =  new int[n];
        ans[n-1] = 0;
        stk.push(n-1);
        for(int i = n-2;i>=0;i--) {
            while(!stk.isEmpty() && temperatures[i] >= temperatures[stk.peek()]){
                stk.pop();
            }
            if(!stk.isEmpty()){
                ans[i] = stk.peek()-i;
            } else {
                ans[i] = 0;
            }
            stk.push(i);
        }
        return ans;
    }
}
