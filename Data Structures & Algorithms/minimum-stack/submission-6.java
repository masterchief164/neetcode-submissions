class MinStack {

    Stack<Integer> stk, minStk;

    public MinStack() {
        stk = new Stack<>();
        minStk = new Stack<>();
    }
    
    public void push(int val) {
        stk.push(val);
        if(minStk.size() == 0) {
            minStk.push(val);
            return;
        }
        int mini = Math.min(val, minStk.peek());
        minStk.push(mini);
    }
    
    public void pop() {
        stk.pop();
        minStk.pop();
    }
    
    public int top() {
        return stk.peek();
    }
    
    public int getMin() {
        return minStk.peek();
    }
}
