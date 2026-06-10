class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer> stk = new Stack<>();

        for(String s: operations) {
            if(s.equals("+")){
                int a = stk.pop();
                int b = stk.pop();

                int ans = a +b;
                stk.push(b);
                stk.push(a);
                stk.push(ans);
            } else if(s.equals("C")) {
                stk.pop();
            } else if(s.equals("D")) {
                int a = stk.pop();
                stk.push(a);
                stk.push(a*2);
            } else {
                stk.push(Integer.parseInt(s));
            }
        }
        return stk.stream().mapToInt(Integer::intValue).sum();
    }
}