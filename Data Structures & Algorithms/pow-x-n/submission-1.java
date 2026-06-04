class Solution {
    public double myPow(double x, int n) {
        if(x==0) return 0;
        if(n==0) return 1;

        double res = 1;
        long pow = Math.abs((long)n);

        while(pow > 0) {
            if((pow & 1) == 1) {
                res*=x;
            }
            x*=x;
            pow >>= 1;
        }

        return n >= 0 ? res: 1/res;
    }
}
