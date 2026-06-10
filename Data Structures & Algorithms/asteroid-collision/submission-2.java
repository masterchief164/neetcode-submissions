class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stk = new Stack<>();

        for (int a : asteroids) {
            boolean destroyed = false;

            while (!stk.isEmpty() && stk.peek() > 0 && a < 0) {
                int top = stk.peek();

                if (Math.abs(top) < Math.abs(a)) {
                    stk.pop();
                } else if (Math.abs(top) == Math.abs(a)) {
                    stk.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break; 
                }
            }

            if (!destroyed) {
                stk.push(a);
            }
        }

        int[] result = new int[stk.size()];
        for (int i = result.length - 1; i >= 0; i--) {
            result[i] = stk.pop();
        }
        
        return result;
    }
}