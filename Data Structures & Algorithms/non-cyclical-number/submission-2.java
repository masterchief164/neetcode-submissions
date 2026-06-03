class Solution {
    public boolean isHappy(int n) {
        Set<Integer> val = new HashSet<>();
        while(!val.contains(n)) {
            if(n == 1) return true;
            // if(n<10)return false;
            val.add(n);
            int sum = 0;
            while(n > 0){
                int d = n%10;
                sum+=d*d;
                n/=10;
            }
            n = sum;
        }
        return false;
    }
}
